#include <iostream>
#include <limits>

namespace std {
// overwrite function 重载函数 : 重载函数，必须定义在std作用域内
ostream& endl(ostream& os){
    // write new line
    os.put('-');
    os.write("hello tycao!\n", 13);

    // flush the output buffer
    os.flush();

    // return os to allow chaining
    return os;
}
}

// unfortunately, below template function is of no use
template<typename charT, typename traits>
inline std::basic_ostream<charT, traits> std::endl(std::basic_ostream<charT, traits>& strm) {
    strm.put(strm.widen('\n'));
    strm.write("the begining prefix of the line\n", 32);
    strm.flush();
    return strm;
}



template<typename charT, typename traits>
inline std::basic_istream<charT, traits>&
ignoreLine(std::basic_istream<charT, traits>& strm) {
    // skip until end-of-line
    strm.ignore(std::numeric_limits<int>::max(), strm.widen('\n'));

    // return stream for concatenation
    return strm;
}

int main(int argc, char *argv[])
{

    std::cout << "------------------->>>>>>>>>>>>>" << std::endl;
    char c;
    std::cin >> ignoreLine >> ignoreLine >> ignoreLine;
    while (std::cin.get(c)) {
        std::cout.put(c);
    }
    return 0;
}
