#include "part.h"

NameContainer partContainer;

// 初始化构造函数
Part::Part(const std::string & n)
    : name(n)
{

}
// 列出part的名字及所有subparts与其对应的数量，并用游标处理subparts
void Part::describe(void)
{
    cout << "Part " << this->name << " subparts are: " << endl;
    // 若subparts不存在，则显示提示信息
    if (subparts.empty())
    {
        cout << "There is no subparts!!!" << endl;
        return;
    }
    for (std::map<Part*, int>::iterator iter = this->subparts.begin(); iter != this->subparts.end(); ++iter)
        cout << iter->second << " " << iter->first->name << endl;
}
// 计算指针p所指向部分的实例个数
int Part::count_howmany(const Part* p)
{
    return myCount(this->subparts, p, 1);
}
// 辅助函数，提供一个数字来记录值
int Part::myCount(std::map<Part*, int>& myMap, const Part* p, int num)
{
    if (myMap.empty())
        return 0;
    for (std::map<Part*, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
    {
        num *= iter->second;
        if (iter->first->name == p->name)
            return num;
        // 如果发现结果无效，则回归到原值
        else if (myCount(iter->first->subparts, p, num) == 0)
            num /= iter->second;
        // 进一步搜索
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
