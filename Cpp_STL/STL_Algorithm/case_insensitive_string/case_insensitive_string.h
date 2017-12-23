#pragma once

#include <string>
#include <iostream>
#include <cctype>   // for toupper()


/*
 * replace functions of the standard char_traits<char>
 * so that strings can behave in a case-insensitive way
*/
struct ignorecase_traits : public std::char_traits<char> {
    // return whether c1 and c2 are equal
    static bool eq(const char& c1, const char& c2);

    // return whether c1 is less than c2
    static bool lt(const char& c1, const char& c2);

    // compare up to n characters of s1 and s2
    static int compare(const char* s1, const char* s2, std::size_t n);

    // search c in s
    static const char* find(const char* s, std::size_t n, const char& c);
};

// global function

// define a special type for such strings
typedef std::basic_string<char, ignorecase_traits> icestring;

/*
 * deifne an output operator
 * because the traits type is different than that for std::ostream
*/
std::ostream& operator << (std::ostream& os, const icestring& s);
