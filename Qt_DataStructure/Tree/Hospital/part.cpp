#include "part.h"

NameContainer partContainer;

// ��ʼ�����캯��
Part::Part(const std::string & n)
    : name(n)
{

}
// �г�part�����ּ�����subparts�����Ӧ�������������α괦��subparts
void Part::describe(void)
{
    cout << "Part " << this->name << " subparts are: " << endl;
    // ��subparts�����ڣ�����ʾ��ʾ��Ϣ
    if (subparts.empty())
    {
        cout << "There is no subparts!!!" << endl;
        return;
    }
    for (std::map<Part*, int>::iterator iter = this->subparts.begin(); iter != this->subparts.end(); ++iter)
        cout << iter->second << " " << iter->first->name << endl;
}
// ����ָ��p��ָ�򲿷ֵ�ʵ������
int Part::count_howmany(const Part* p)
{
    return myCount(this->subparts, p, 1);
}
// �����������ṩһ����������¼ֵ
int Part::myCount(std::map<Part*, int>& myMap, const Part* p, int num)
{
    if (myMap.empty())
        return 0;
    for (std::map<Part*, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
    {
        num *= iter->second;
        if (iter->first->name == p->name)
            return num;
        // ������ֽ����Ч����ع鵽ԭֵ
        else if (myCount(iter->first->subparts, p, num) == 0)
            num /= iter->second;
        // ��һ������
        else
            return myCount(iter->first->subparts, p, num);
    }
}

NameContainer::~NameContainer()
{
    for (std::map<std::string, Part*>::iterator iter = name_map.begin(); iter != name_map.end(); ++iter)
        delete iter->second;
}
NameContainer::NameContainer(void)
{

}
Part* NameContainer::lookup(const std::string& name)
{
    if (this->name_map.find(name) == this->name_map.end())
    {
        Part* part = new Part(name);
        name_map.insert(std::make_pair(name, part));
        return part;
    }
    else
        return name_map.find(name)->second;
}

void add_part(const std::string& x, int q, const std::string& y)
{
    Part* px = partContainer.lookup(x);
    Part* py = partContainer.lookup(y);
    px->subparts.insert(std::make_pair(py, q));
}
