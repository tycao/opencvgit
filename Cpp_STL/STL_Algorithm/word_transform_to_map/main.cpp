#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream& map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    // 读取第一个单词存入key中，行中剩余内容存入value(除去第一个空格)
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);   // 去除空格
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string& transform(const string& s, const map<string, string>& m) {
    // 实际的转换工作：此部分是程序的核心
    map<string, string>::const_iterator map_iter = m.find(s);
    if (map_iter != m.end())
        return map_iter->second;
    else
        return s;
}

// word_transform函数
void word_transform(ifstream& map_file, ifstream& input) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {  //读取一行输入
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";    // 在单词间 打印一个空格
            // transform返回它的第一个参数，或其转换之后的形式
            cout << transform(word, trans_map);
        }
        cout << "\n";   // 完成一行的转换
    }
}


int main(int argc, char *argv[])
{
    ifstream map_file("e:\\word_map.txt"), input("e:\\text.txt");
    word_transform(map_file, input);

    return 0;
}
