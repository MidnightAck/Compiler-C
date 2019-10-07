#pragma once
#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<vector>
#include "utils.h"

using namespace std;

class LexicalAnalyzer {
private:
    //所有运算符
    set<string> OPERATORS = { "+", "-", "*", "/", "=", "==", ">", ">=", "<", "<=", "!="};

    //关键字
    set<string> KEYWORDS = { "if", "else", "return", "while"};

    //变量类型
    set<string> TYPES = {"int", "void", "char", "float"};

    //前置运算符
    set<string> PRE_OPERATORS = { "+", "-"};

    //界符
    set<char> BORDERS = { '(', ')', '{', '}', ',', ';'};

    ifstream code_reader_;
    ofstream lexical_analyser_printer_;

    unsigned int line_counter_;//用于词法分析发生错误时的行数定位
    bool print_detail_;//选择是否将词法分析结果输出到txt中
    unsigned int step_counter_;//词法分析计步器
    bool IsDot(const unsigned char ch);					  //是否为小数点
    bool IsLetter(const unsigned char ch);//是否字母
    bool IsDigital(const unsigned char ch);//是否数字
    bool IsSingleCharOperator(const unsigned char ch);//是否单符号运算符
    bool IsDoubleCharOperatorPre(const unsigned char ch);//是否双符号运算符
    bool IsBlank(const unsigned char ch);//是否是空白符
    unsigned char GetNextChar();//获取字符流中的下一个字符，同时计算行数。
    vector<unsigned char> vec1;//双缓冲区
    vector<unsigned char> vec2;
    vector<unsigned char> now;
    int nextBuffer=1;//下一次应该使用的缓冲区
    int bufferPlace = 0;
    int bufferSum = 0;//表示当前缓冲区的总字符数
    bool wetherBack = false;
    bool fileEnd = false;//表示到达文件末尾
    void PrintDetail(WordInfo word);//打印词法分析信息
    WordInfo GetBasicWord();//获取文法符号,但是无法进行打印

public:
    LexicalAnalyzer();
    ~LexicalAnalyzer();
    bool IsReadyToAnalyze(bool show_detail, const string code_filename);//文件是否读到
    WordInfo GetWord();//获取文法符号，可进行打印信息。
    void packBuffer();
    unsigned char getBufferChar();
    void returnBufferPlace();
};


#endif