#include "dictionary.h"

// ��hash_function
hash_function::hash_function() { } // Ĭ�Ϲ��캯��

unsigned int hash_function::operator ()(const std::string& s) const   // ���غ����������������������������
{
    unsigned int res = 0;
    for (int i = 0; i < s.size(); ++i)
        res = res * 1000 + s.at(i);
    return res;
}

// ��equality
equality::equality() { }  // Ĭ�Ϲ��캯��

bool equality::operator ()(const std::string& A, const std::string& B) const // ���غ����������������������������
{
    return A == B;
}


// ��Dictionary
Dictionary::Dictionary(const std::string& filename)    // ���캯��
{
    infile.open(filename.c_str());
    if (!infile)
    {
        cerr << "can not open " << filename + " for input.\n";
        return;
    }
    string line;
    while (getline(infile, line))
        insert(line);
    infile.close();
}
