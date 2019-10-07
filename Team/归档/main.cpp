#include <iostream>
#include <fstream>
#include "lexical_analyzer.h"
#include "utils.h"

using namespace std;

int main() {
    string code_filename="test.cpp";
    LexicalAnalyzer lexcial_analyzer;
    if (!lexcial_analyzer.IsReadyToAnalyze(true, code_filename))
        return false;
    while (true) {
        WordInfo get_word = lexcial_analyzer.GetWord();
    }
}