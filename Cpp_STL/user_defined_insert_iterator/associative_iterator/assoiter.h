#pragma once

#include <iterator>

/*
 * ����һ������ʽ������insert������ ��ģ����Ĵ���Դ����
*/
template<typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
    // ���캯��
    explicit asso_insert_iterator(Container& c)
        : container(c)
    {

    }

    // ������ֵ�����
    // ��һ�����ݲ��뵽������
    asso_insert_iterator<Container>& operator =(const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    // �����������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator *()
    {
        return *this;
    }

    // ǰ�õ��������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator ++()
    {
        return *this;
    }

    // ���õ��������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator ++(int)
    {
        return *this;
    }
protected:
    Container& container;   // Ԫ����Ҫ���뵽��������
private:

};

// ���򵥵Ľӿڣ������������������
// �Ǹ��������� �� �������Ϳ���չ���ú�������������ʱ����
template<typename Container>
inline asso_insert_iterator<Container> asso_insert(Container& c)
{
    return asso_insert_iterator<Container>(c);
}
