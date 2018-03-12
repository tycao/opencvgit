#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <cstdlib>

using namespace std;

using line_no = vector<string>::size_type;

vector<string> file;    // 文件每行的内容
map<string, set<line_no>> wm;   // 单词到行号的set映射

string cleanup_str(const string& word) {
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it)) {    // 单词中是否存在标点符号(若没有)
            ret += tolower(*it);
        }
    }
    return ret;
}

void input_text(ifstream& is) {
    string text;
    while (getline(is, text)) { // 对文件里的每一行
        file.push_back(text);   // 保存此行到vector容器中
        int n = file.size() - 1;    //当前行号
        istringstream line(text);
        string word;
        while (line >> word) {
            wm[cleanup_str(word)].insert(n);
        }
    }
}

ostream &query_and_print(const string& sought, ostream& os) {
    // 使用find而不是下表运算符来查找单词，以避免将单词添加到wm中！
    map<string, set<line_no>>::iterator loc = wm.find(sought);
    if (loc == wm.end()) {
        os << sought << "出现了0次！\n";
    } else {
        set<line_no> lines = loc->second;    // 行号set
        os << sought << " 出现了" << lines.size() << "次。\n";
        for (auto & num: lines) {
            os << "\t（第" << num + 1 << "行）"
               << *(file.begin() + num) << "\n";
        }
    }
    return os;
}

void runQueries(ifstream& infile) {
    // infile 是一个ifstream，指向我们要查询的文件
    input_text(infile);
    // 和用户交互，提示用户输入需要查询的单词，完成查询，并打印错误
    while (true) {
        cout << "input word to look for, or 'q' to quit: ";
        string s;
        // 若遇到文件尾部 或者 用户输入了q，退出循环
        if (!(cin >> s) || s == "q") {
            break;
        }
        // 指向查询，并打印结果
        query_and_print(s, cout) << "\n";
    }
}

int main(int argc, char *argv[])
{
    // 打开要查询的文件
    ifstream infile;
    infile.open(string("C:\\Users\\Administrator\\Desktop\\new2.txt"));
    // 若打开文件失败，程序异常退出
    if (!infile) {
        cerr << "打开文件失败！\n";
        return EXIT_FAILURE;
    }
    runQueries(infile);
    return 0;
}
