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
    std::string wordlist("C:\\Users\\Administrator\\Downloads\\wordlist.txt");
    std::string test("C:\\Users\\Administrator\\Downloads\\test.txt");

    std::ifstream inf(test);
    if (!inf)
    {
        std::cerr << "failed to open the file, please try again later." << endl;
        return EXIT_FAILURE;
    }
    std::cout << "字典载入中...这个过程可能需要几分钟..." << endl;

    Dictionary d(wordlist);
    check_spelling(inf, d);
    inf.close();

    return EXIT_SUCCESS;
}

// 将单词全部转换为小写
void lower(string& s)
{
    for (int i = 0; i < s.length(); ++i)
        s[i] = tolower(s[i]);
}
// 去除单词中首尾字符
std::string strip_punct(const std::string& s)
{
    if (ispunct(s[s.length() - 1])) // 若最后一个字符是标点符号
        return s.substr(0, s.length() - 1); // 删除最后一个字符
    else
        return s;
}
// （对比词库）检查单词是否拼写正确
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
            word = strip_punct(word);   // 若单词最后一位是标点符号，删除该标点符号
            lower(word);    // 使单词全部小写
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
// 若单词拼写有误，则给出"拼写将近"的单词
void spellingSuggestionOne(Dictionary& dict, const string& word)    // 交换单词里的任意相邻字符，判断交换后的单词是否在词库里
{
    std::string temp = "";
    std::string foregoing = "";
    for (int i = 0; i != word.size() - 1; ++i)
    {
        temp = word;
        // 交换相邻字母
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
void spellingSuggestionTwo(Dictionary& dict, const string& word)    // 删除单词里的任意一个字符，判断删除后的单词是否在词库里
{
    string temp = "";
    string foregoing = "";
    for (int i = 0; i != word.size(); ++i)
    {
        temp = word;
        // 删除一个字符
        temp.erase(i, 1);   // string的erase用法
        if (dict.search(temp) && temp != foregoing)
        {
            foregoing = temp;
            cout << "\t\t\t" << temp << endl;
        }
    }
}
void spellingSuggestionThr(Dictionary& dict, const string& word)    // 替换单词里任意一个字符，判断替换后的单词是否在字库里
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
