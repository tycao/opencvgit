#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);  // 将单词全部转换为小写
std::string strip_punct(const std::string& s);  // 去除单词中首尾字符
void check_spelling(std::ifstream& in, Dictionary& dict);  // （对比词库）检查单词是否拼写正确
// 若单词拼写有误，则给出"拼写将近"的单词
void spellingSuggestionOne(Dictionary& dict, const string& word);
void spellingSuggestionTwo(Dictionary& dict, const string& word);
void spellingSuggestionThr(Dictionary& dict, const string& word);
void spellingSuggestionFou(Dictionary& dict, const string& word);

int main(int argc, char *argv[])
{
    return 0;
}
