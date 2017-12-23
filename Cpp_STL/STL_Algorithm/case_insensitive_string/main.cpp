#include "case_insensitive_string.h"

int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;

    icestring s1("hallo");
    icestring s2("otto");
    icestring s3("hALLo");

    cout << std::boolalpha;
    cout << s1 << "==" << s2 << " : " << (s1 == s2) << endl;
    cout << s1 << "==" << s3 << " : " << (s1 == s3) << endl;

    icestring::size_type idx = s1.find("ALL");
    if (idx != icestring::npos) {
        cout << "index of \"ALL\" in \"" << s1 << "\" : "
             << idx << endl;
    }
    else {
        cout << "\"ALL\" not found in \"" << s1 << endl;
    }

    return 0;
}
