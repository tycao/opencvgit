#include "case_insensitive_string.h"

// return whether c1 and c2 are equal
bool ignorecase_traits::eq(const char& c1, const char& c2) {
    return std::toupper(c1) == std::toupper(c2);
}

// return whether c1 is less than c2
bool ignorecase_traits::lt(const char& c1, const char& c2){
    return std::toupper(c1) < std::toupper(c2);
}

// compare up to n characters of s1 and s2
int ignorecase_traits::compare(const char* s1, const char* s2, std::size_t n) {
    for (std::size_t i = 0; i != n; ++i) {
        if (!eq(s1[i], s2[i])) {
            return lt(s1[i], s2[i]) ? -1 : 1;
        }
    }
    return 0;
}

// search c in s
const char* ignorecase_traits::find(const char* s, std::size_t n, const char& c) {
    for (std::size_t i = 0; i != n; ++i) {
        if (eq(s[i], c)) {
            return &(s[i]);
        }
    }
    return 0;
}

// global function

std::ostream& operator << (std::ostream& os, const icestring& s) {
    // simply convert the icestring into a normal string
    return os << std::string(s.data(), s.length());
}
