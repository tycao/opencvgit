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
    std::string wordlist("C:\\Users\\Administrator\\Downloads\\wordlist.txt");
    std::string test("C:\\Users\\Administrator\\Downloads\\test.txt");

    std::ifstream inf(test);
    if (!inf)
    {
        std::cerr << "failed to open the file, please try again later." << endl;
        return EXIT_FAILURE;
    }
    std::cout << "�ֵ�������...������̿�����Ҫ������..." << endl;

    Dictionary d(wordlist);
    check_spelling(inf, d);
    inf.close();

    return EXIT_SUCCESS;
}

// ������ȫ��ת��ΪСд
void lower(string& s)
{
    for (int i = 0; i < s.length(); ++i)
        s[i] = tolower(s[i]);
}
// ȥ����������β�ַ�
std::string strip_punct(const std::string& s)
{
    if (ispunct(s[s.length() - 1])) // �����һ���ַ��Ǳ�����
        return s.substr(0, s.length() - 1); // ɾ�����һ���ַ�
    else
        return s;
}
// ���Աȴʿ⣩��鵥���Ƿ�ƴд��ȷ
void check_spelling(std::ifstream& in, Dictionary& dict)
{
    int line_number = 0;
    std::string line;
    while (getline(in, line))
    {
        ++line_number;
        std::stringstream ss;
        ss << line;
        string word;
        while (ss >> word)
        {
            word = strip_punct(word);   // ���������һλ�Ǳ����ţ�ɾ���ñ�����
            lower(word);    // ʹ����ȫ��Сд
            if (!dict.search(word))
            {
                cout << "line " << line_number << ":    \'" << word << "\'" << endl;
                cout << "\tsuggestions:" << endl;
                spellingSuggestionOne(dict, word);
                spellingSuggestionTwo(dict, word);
                spellingSuggestionThr(dict, word);
                spellingSuggestionFou(dict, word);
            }
        }
    }
}
// ������ƴд���������"ƴд����"�ĵ���
void spellingSuggestionOne(Dictionary& dict, const string& word)    // ��������������������ַ����жϽ�����ĵ����Ƿ��ڴʿ���
{
    std::string temp = "";
    std::string foregoing = "";
    for (int i = 0; i != word.size() - 1; ++i)
    {
        temp = word;
        // ����������ĸ
        char tempChar = temp[i];
        temp[i] = temp[i + 1];
        temp[i + 1] = tempChar;
        if (dict.search(temp) && temp != foregoing)
        {
            foregoing = temp;
            cout << "\t\t\t" << temp << endl;
        }
    }
}
void spellingSuggestionTwo(Dictionary& dict, const string& word)    // ɾ�������������һ���ַ����ж�ɾ����ĵ����Ƿ��ڴʿ���
{
    string temp = "";
    string foregoing = "";
    for (int i = 0; i != word.size(); ++i)
    {
        temp = word;
        // ɾ��һ���ַ�
        temp.erase(i, 1);   // string��erase�÷�
        if (dict.search(temp) && temp != foregoing)
        {
            foregoing = temp;
            cout << "\t\t\t" << temp << endl;
        }
    }
}
void spellingSuggestionThr(Dictionary& dict, const string& word)    // �滻����������һ���ַ����ж��滻��ĵ����Ƿ����ֿ���
{
    string temp = "";
    string foregoing = "";
    string str = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i != word.size(); ++i)
    {
        temp = word;
        for (int j = 0; j != 26; ++j)
        {
            temp = word;
            temp.replace(i, 1, str.substr(j, 1));
            if (dict.search(temp) && temp != foregoing)
            {
                foregoing = temp;
                cout << "\t\t\t" << temp << endl;
            }
        }
    }
}
void spellingSuggestionFou(Dictionary& dict, const string& word)
{
    std::string temp = "";
    std::string foregoing = "";
    std::string str = "qwertyuiopasdfghjklzxcvbm";
    for (int i = 0; i != word.size() + 1; ++i)
    {
        temp = word;
        for (int j = 0; j != 26; ++j)
        {
            temp = word;
            temp.insert(i, str.substr(j, 1));
            if (dict.search(temp) && temp != foregoing)
            {
                foregoing = temp;
                cout << "\t\t\t" << temp << endl;
            }
        }
    }
}
