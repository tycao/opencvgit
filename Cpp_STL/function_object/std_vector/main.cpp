#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


int main(int argc, char *argv[])
{
    // create empty vector for strings
    std::vector<std::string> sentence;

    // reserve memory for five elements to avoid reallocation
    sentence.reserve(5);

    // append some elements
    sentence.push_back("Hello, ");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");

    // print elements separated with spaces
    std::copy(sentence.begin(), sentence.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    // print "technical data"
    std::cout << "max_size() : " << sentence.max_size() << std::endl;
    std::cout << "size() : " << sentence.size() << std::endl;
    std::cout << "capacity() : " << sentence.capacity() << std::endl;

    // swap the 2nd and 4th element
    std::swap(sentence[1], sentence[3]);

    // insert element "always" before "?"
    sentence.insert(std::find(sentence.begin(), sentence.end(), "?"), "always");

    std::copy(sentence.cbegin(), sentence.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    // replace "!" with the last element
    sentence.back() = "!";

    // print elements separated with spaces
    std::copy(sentence.cbegin(), sentence.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    // print "technical data"
    std::cout << "max_size() : " << sentence.max_size() << std::endl;
    std::cout << "size() : " << sentence.size() << std::endl;
    std::cout << "capacity() : " << sentence.capacity() << std::endl;

    return 0;
}
