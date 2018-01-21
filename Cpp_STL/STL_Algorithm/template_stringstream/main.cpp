#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

struct Test {
    int a;
    double b;
    long long c;
};

void f(const std::string& str) {
    cout << str << endl;
}

void fun(int i) {
    std::stringstream ss;
    ss << i;
    f(ss.str());
}

void func2(char const* c) {
    std::stringstream ss;
    ss << c;
    int i;
    ss >> i;
    cout << i << endl;
    fun(i);
}

int main(int argc, char *argv[])
{
#if 0
    Test test = {10, 20.0, 1000LL};
//    char* ch = reinterpret_cast<char*>(&test);
//    Test test2 = *reinterpret_cast<Test*>(ch);
//    cout << test2.a << " " << test2.b << " " << test2.c;
    ofstream out("c:\\out.txt");
    out.write(reinterpret_cast<char*>(&test), sizeof(Test));
    out.close();

    ifstream in("c:\\out.txt");
    char* ch = new char[sizeof(Test)];
    memset(ch, 0, sizeof(Test));
    in.read(ch, sizeof(Test));
    in.close();

    Test* test2 = reinterpret_cast<Test*>(ch);
    cout << test2->a << " " << test2->b << " " << test2->c;
#endif

    func2("123");
    return 0;
}
