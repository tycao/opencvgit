#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);  // ������ȫ��ת��ΪСд
std::string strip_punct(const std::string& s);  // ȥ����������β�ַ�
void check_spelling(std::ifstream& in, Dictionary& dict);  // ���Աȴʿ⣩��鵥���Ƿ�ƴд��ȷ
// ������ƴд���������"ƴд����"�ĵ���
void spellingSuggestionOne(Dictionary& dict, const string& word);
void spellingSuggestionTwo(Dictionary& dict, const string& word);
void spellingSuggestionThr(Dictionary& dict, const string& word);
void spellingSuggestionFou(Dictionary& dict, const string& word);

int main(int argc, char *argv[])
{
    return 0;
}
