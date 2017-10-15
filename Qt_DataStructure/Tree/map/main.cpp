#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    std::map<std::string, std::string> writers;
    writers["Shakespear"] = "English writer, his works include 'Hamlet', 'othello', 'King Lear', etc.";
    writers["Tagore"] = "India writers, his works include 'Gitanjail', etc.";
    writers["Tolstory"] = "Russia writers, his works include 'War and Peace', 'Anna Kether', etc.";
    writers["Dumas"] = "French writers, his works include 'The Country of Monte Crite', etc.";

    cout << writers.size() << endl;
    int count = 1;
    for (std::map<std::string, std::string>::iterator it = writers.begin(); it != writers.end(); ++it)
    {
        cout << count << " : " << endl;
        cout << it->first << ": " << it->second << endl;
        ++count;
    }
    cout << "\n\n";

    cout << writers.find("Tagore")->second  << "\n\n";
    writers.erase(writers.find("Tagore"));
    cout << writers.size() << endl;
    writers.clear();
    cout << writers.size() << endl;
    return 0;
}
