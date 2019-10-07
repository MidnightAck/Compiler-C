#include <iostream>
#include <fstream>
#include "lexical_analyzer.h"
#include "utils.h"

using namespace std;

int main(int argc,char* argv[]) {

	//std::cout <<argc << std::endl;//输出参数的个数
	//for (int i = 0; i < argc; i++) {
	//	std::cout <<i<< argv[i] << std::endl;//输出具体参数
	//}

	/*测试的时候注释掉
    string code_filename=argv[1];
	cout << code_filename << endl;
	*/
	char c = '1';
	string code_filename = "test.cpp";
    LexicalAnalyzer lexcial_analyzer;
    if (!lexcial_analyzer.IsReadyToAnalyze(true, code_filename))
        return false;
	lexcial_analyzer.packBuffer();
    while (true) {
        WordInfo get_word = lexcial_analyzer.GetWord();
		if (get_word.type == LEOF)	break;
    }
	system("pause");
	return 0;
}