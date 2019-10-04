#include"lexical_analyzer.h"
const char *TypeTranslation[] = { "NUM", "KEYWARD", "IDENTIFIER", "TYPE", "BOARDER", "UNKNOWN", "EOF", "OPERATOR" };

bool LexicalAnalyzer::IsReadyToAnalyze(bool show_detail, const string code_filename)
{
	if (show_detail)//是否在整个过程中显示词法分析的步骤
	{
		print_detail_ = true;
		lexical_analyser_printer_.open("./gen_data/lexcial_analyzer/lexical_analyser_result.txt");
		if (!lexical_analyser_printer_.is_open()) {
			cerr << "词法分析过程中，显示输出结果文件打开失败！" << endl;
		}
	}
	else
		print_detail_ = false;

	code_reader_.open(code_filename);
	//ios::binary 这里不能用Binary， 因为test.cpp是在win操作系统下创建的，在内存中换行是\r\n。
	//这个时候如果直接从使用二进制读出来，就是\r\n

	if (!code_reader_.is_open()) {
		cerr << "词法分析过程中，源代码文件打开失败！" << endl;
		return false;
	}
	return true;
}

bool LexicalAnalyzer::IsLetter(const unsigned char ch) {
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || '_' == ch )//包含下划线
		return true;
	else
		return false;
}

bool LexicalAnalyzer::IsDigital(const unsigned char ch) {
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}

bool LexicalAnalyzer::IsSingleCharOperator(const unsigned char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

bool LexicalAnalyzer::IsDoubleCharOperatorPre(const unsigned char ch)
{
	if (ch == '=' || ch == '<' || ch == '>' || ch == '!')
		return true;
	else
		return false;
}

bool LexicalAnalyzer::IsBlank(const unsigned char ch) {
	if (' ' == ch || '\n' == ch || '\t' == ch || 255 == ch)
		return true;
	else
		return false;
}

unsigned char LexicalAnalyzer::GetNextChar()
{
	unsigned char ch = code_reader_.get();
	if ('\n' == ch)
		line_counter_++;
	return ch;
}

void LexicalAnalyzer::packBuffer() {
	int sum = 0;
	unsigned char ch;
	unsigned char next;
	bool noteMode=false;
	bool stringMode=false;
	if (nextBuffer == 1) {
		vec1.clear();
		vec2 = now;
		now = vec1;
		nextBuffer = 2;//
	}
	else {
		vec2.clear();
		vec1 = now;
		now = vec2;
		nextBuffer = 1;
	}
	while (sum < 120 && !code_reader_.eof()) {
		ch = GetNextChar();
		if (ch == '/')//处理注释
		{
			noteMode = true;
			next = GetNextChar();
			if (next == '/')//双斜杠注释
			{
				while (GetNextChar() != '\n' && !code_reader_.eof());//到回车为止
				noteMode = false;
			}
			else if (next == '*')// /**/注释
			{
				while (!code_reader_.eof())
				{
					while (GetNextChar() != '*' && !code_reader_.eof());//到*为止

					//UNKNOWN
					if (code_reader_.eof())//非正常完结的注释
					{
						cout << "ERROR End" << endl;
					}

					//  /**/ 注释结束
					if (GetNextChar() == '/') {
						noteMode = false;
						break;
					}
				}
			}
			else//这是个除号
			{
				code_reader_.seekg(-1, ios::cur);//输入文件指针回退,因为多读了next
				now.push_back(ch);
				sum++;
			}
		}
		else {
			now.push_back(ch);
			sum++;
			if (ch == ' ') {//去空格
				while (GetNextChar() == ' ' && !code_reader_.eof());//到下一个不是空格为止
				code_reader_.seekg(-1, ios::cur);//回退
			}
		}
	}
	if (code_reader_.eof()) {
		fileEnd = true;
	}
	bufferSum = sum;
}

unsigned char LexicalAnalyzer::getBufferChar()
{
	if (bufferPlace >= bufferSum && fileEnd == true) {//假如EOF了就返回上一个而不是现在的
		return now[bufferPlace-1];
	}
	unsigned char ch;
	if (bufferPlace == 120) {
		if (wetherBack = true) {//假如是从上一个缓冲区退回来的,则此时下一个缓冲区已经装填好了
			wetherBack = false;
			if (nextBuffer == 1) {
				now = vec1;
				bufferPlace = 0;
			}
			else{
				now = vec2;
				bufferPlace = 0;
			}
		}
		else {
			packBuffer();
			bufferPlace = 0;
		}
	}
	ch = now[bufferPlace];
	bufferPlace++;
	return ch;
}
void LexicalAnalyzer::returnBufferPlace() {
	if (bufferPlace != 0) {
		bufferPlace--;
	}
	else {//假如是零则要退到上一个缓冲区
		if (nextBuffer == 1) {
			now = vec1;
			nextBuffer = 2;
			bufferPlace = 119;
			wetherBack = true;
		}
		else {
			now = vec2;
			nextBuffer = 1;
			bufferPlace = 119;
			wetherBack = true;
		}
	}
}
WordInfo LexicalAnalyzer::GetBasicWord() {
	unsigned char ch;
	string str_token;
	WordInfo word;

	while (!(bufferPlace >= bufferSum && fileEnd == true))//表示EOF的情况
	{
		ch = getBufferChar();
		if (IsDigital(ch))
		{
			str_token += ch;
			while (!(bufferPlace >= bufferSum && fileEnd == true)) {
				unsigned char next = getBufferChar();
				if (!IsDigital(next)) //下一个不是数字，需要退回
				{
					returnBufferPlace();//输入文件指针回退,因为多读了next
					word.type = LCINT; //int数
					word.value = str_token;
					return word;
				}
				else  //下一个还是数字，继续循环
					str_token += next;
			}
		}
		else if (IsLetter(ch))
		{
			str_token += ch;
			while (!(bufferPlace == bufferSum && fileEnd == true)) {
				unsigned char next = getBufferChar();
				if ((!IsDigital(next)) && (!IsLetter(next))) //下一个不是字母或数字，需要退回
				{
					code_reader_.seekg(-1, ios::cur);//输入文件指针回退,因为多读了next
					
					//判断是否为关键字、变量类型
					if (KEYWORDS.find(str_token) != KEYWORDS.end()) //在关键字中
						word.type = LKEYWORD; 
					else if (TYPES.find(str_token) != TYPES.end()) //在变量类型中
						word.type = LTYPE; 
					else //标识符
						word.type = LIDENTIFIER; 

					word.value = str_token;
					return word;
				}
				else  //下一个还是字母或数字，继续循环
					str_token += next;
			}
		}
		else if (BORDERS.find(ch) != BORDERS.end())
		{
			word.type = LBORDER; //边界
			word.value = ch;
			return word;
		}
		else if (IsSingleCharOperator(ch))//单符号运算符
		{
			word.type = LOPERATOR; //操作符
			word.value = ch;
			return word;
		}
		else if (IsDoubleCharOperatorPre(ch))//判断是否为双符号运算符
		{
			str_token += ch;
			unsigned char next = getBufferChar();

			if ('=' == next) //确定是双符号运算符
			{
				str_token += next;
				word.type = LOPERATOR; //操作符
				word.value = str_token;
				return word;
			}
			else
			{
				returnBufferPlace();//输入文件指针回退,因为多读了next
				if (ch != '!')//是个单符号操作符
				{
					word.type = LOPERATOR; //操作符
					word.value = str_token;
					return word;
				}
				else// ! 未定义的符号
				{
					word.type = LUNKNOWN; //操作符
					word.value = str_token + ", line: " + std::to_string(line_counter_);
					return word;
				}
			}
			
		}
		else if (IsBlank(ch))
		{
			continue;
		}
		else
		{
			word.type = LUNKNOWN;
			word.value = ch;
			word.value += ", line: " + std::to_string(line_counter_);
			return word;
		}
	}


	word.type = LEOF;
	word.value = "#";
	return word;
}

WordInfo LexicalAnalyzer::GetWord()
{
	WordInfo get_word = GetBasicWord();
	string word_string;
	if (get_word.type == LEOF)
		word_string = "#";
	else if (get_word.type == LCINT)
		word_string = "num";
	else if (get_word.type == LKEYWORD || get_word.type == LTYPE ||
		get_word.type == LBORDER || get_word.type == LOPERATOR)
		//KEYWORDS = { "if", "else", "return", "while"};
		//TYPES = { "int", "void" };
		//BORDERS = { '(', ')', '{', '}', ',', ';'};
		//OPERATORS = { "+", "-", "*", "/", "=", "==", ">", ">=", "<", "<=", "!="};
		word_string = get_word.value;
	else if (get_word.type == LTYPE)
		word_string = get_word.value;
	else if (get_word.type == LIDENTIFIER)
		word_string = "identifier";
	else { ; }

	get_word.word_string = word_string;

	if (print_detail_)
		PrintDetail(get_word);
	return get_word;
}

void LexicalAnalyzer::PrintDetail(WordInfo word)
{
	if (word.type == LEOF)
		return;
	lexical_analyser_printer_ << "step " << step_counter_ << " , type: " << TypeTranslation[word.type] << " , value: " << word.value;
	if(word.type == LUNKNOWN)
		lexical_analyser_printer_ << "    ****** warning! ******";
	lexical_analyser_printer_ << endl;
	step_counter_++;
	return;
}

LexicalAnalyzer::LexicalAnalyzer()
{
	line_counter_ = 1;
	step_counter_ = 1;
	print_detail_ = false;
}

LexicalAnalyzer::~LexicalAnalyzer()
{
	if (code_reader_.is_open())
		code_reader_.close();

	if (lexical_analyser_printer_.is_open())
		lexical_analyser_printer_.close();
}


