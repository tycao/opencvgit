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

vector<string> file;    // �ļ�ÿ�е�����
map<string, set<line_no>> wm;   // ���ʵ��кŵ�setӳ��

string cleanup_str(const string& word) {
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it)) {    // �������Ƿ���ڱ�����(��û��)
            ret += tolower(*it);
        }
    }
    return ret;
}

void input_text(ifstream& is) {
    string text;
    while (getline(is, text)) { // ���ļ����ÿһ��
        file.push_back(text);   // ������е�vector������
        int n = file.size() - 1;    //��ǰ�к�
        istringstream line(text);
        string word;
        while (line >> word) {
            wm[cleanup_str(word)].insert(n);
        }
    }
}

ostream &query_and_print(const string& sought, ostream& os) {
    // ʹ��find�������±�����������ҵ��ʣ��Ա��⽫������ӵ�wm�У�
    map<string, set<line_no>>::iterator loc = wm.find(sought);
    if (loc == wm.end()) {
        os << sought << "������0�Σ�\n";
    } else {
        set<line_no> lines = loc->second;    // �к�set
        os << sought << " ������" << lines.size() << "�Ρ�\n";
        for (auto & num: lines) {
            os << "\t����" << num + 1 << "�У�"
               << *(file.begin() + num) << "\n";
        }
    }
    return os;
}

void runQueries(ifstream& infile) {
    // infile ��һ��ifstream��ָ������Ҫ��ѯ���ļ�
    input_text(infile);
    // ���û���������ʾ�û�������Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ������ӡ����
    while (true) {
        cout << "input word to look for, or 'q' to quit: ";
        string s;
        // �������ļ�β�� ���� �û�������q���˳�ѭ��
        if (!(cin >> s) || s == "q") {
            break;
        }
        // ָ���ѯ������ӡ���
        query_and_print(s, cout) << "\n";
    }
}

int main(int argc, char *argv[])
{
    // ��Ҫ��ѯ���ļ�
    ifstream infile;
    infile.open(string("C:\\Users\\Administrator\\Desktop\\new2.txt"));
    // �����ļ�ʧ�ܣ������쳣�˳�
    if (!infile) {
        cerr << "���ļ�ʧ�ܣ�\n";
        return EXIT_FAILURE;
    }
    runQueries(infile);
    return 0;
}
