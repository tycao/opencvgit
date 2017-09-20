#pragma once

#include "doulistnode.h"

template<typename T>
class DouList
{
public:
    DouList();  // 默认构造函数
    DouList(T); // 转换构造函数
    ~DouList() { }  // 析构函数
    bool AddTail(T);
    bool AddHead(T);
    void RemoveThis(bool);
    void RemoveAll();
    void Setbegin();
    int GetCount();
    void TowardCur();
    void BackCur();
    DouListNode<T>* GetCur();
    DouListNode<T>* GetHead();
    DouListNode<T>* GetTail();
    void InsertAfter(T);
    bool IsEmpty();
    T GetNext();
    T GetPrior();
private:
    DouListNode<T>* head;
    DouListNode<T>* tail;
    DouListNode<T>* cur;
};
// 成员函数的实现
// 默认构造函数
template<typename T>
DouList<T>::DouList()
{
    head = tail = new DouListNode<T>();
    cur = nullptr;
    head->SetLink(head);    // 创建初始循环
    head->SetPrior(tail);
}
// 转换构造函数
template<typename T>
DouList<T>::DouList(T value)
{
    head = tail = new DouListNode<T>(value);
    cur = nullptr;
    head->SetLink(head);    // 创建初始循环
    head->SetPrior(tail);
}
// 在表尾插入一个新节点
template<typename T>
bool DouList<T>::AddTail(T value)
{
    // 创建新节点，节点存储的数据由value决定
    DouListNode<T>* add = new DouListNode<T>(value);
    tail->SetLink(add); //使新创建的节点成为表尾节点的后继结点
    add->SetPrior(tail);    // 使表尾节点成为新创建节点的前驱结点
    tail = tail->GetLink(); // 使 新创建的节点成为新的表尾节点
    tail->SetLink(head);    // 使新的表尾节点的后继结点，指向表头节点
    head->SetPrior(tail);   // 设置表头节点的前驱结点为新的表尾节点。至此插入操作完成。
    // 若新的表尾节点为空，则插入失败
    if (tail != nullptr)
        return true;
    else
        return false;
}

// 此函数用来向表头节点与链表中第一个节点之间插入新节点
template<typename T>
bool DouList<T>::AddHead(T value)
{
    // 创建新节点，保存数据value
    DouListNode<T>* add = new DouListNode<T>(value);
    add->SetPrior(head);    //将新创建的节点的前驱结点，指向表头节点
    add->SetLink(head->GetLink());  // 将新创建的节点的后继结点，指向表头节点的后继结点
    // 将新创建的节点，设置为链表中的第一个节点
    // 将链表的第一个节点的前驱结点设置为新创建的节点
    head->SetLink(add); // 将表头节点的后继结点，设置为新创建的节点
    head->GetLink()->SetPrior(add); // 将表头节点的后继结点的前驱结点，设置为新创建的节点
    // 若对空链表应用这个函数，则应该更新表尾指针
    if (tail == head)
        tail = head->GetLink();
    if (tail != nullptr)
        return true;
    else
        return false;
}

// 把当前cur指向的节点删除，删除后cur的移动方向由bool direction决定
template<typename T>
void DouList<T>::RemoveThis(bool direction)
{
    // 若当前cur位于表头处，由于表头节点不能被删除，顺序移动cur至下一个节点
    if (cur == head)
    {
        // 若direction == false，则顺着link方向移动cur
        // 若direction == true,则 顺着prior方向移动cur
        if (direction == false)
            cur = cur->GetLink();
        else
            cur = cur->GetPrior();
    }
    // 新建指针preCur 与 nextCur : preCur指向cur的前驱结点；nextCur指向cur的后继结点
    DouListNode<T>* preCur = cur->GetPrior();   // cur的前驱结点
    DouListNode<T>* nextCur = cur->GetLink();   // cur的后继结点

    preCur->SetLink(nextCur);   // 使cur的前驱结点，指向cur的后继结点
    nextCur->SetPrior(preCur);  // 使cur的后继结点，重新指向cur的前驱结点
    // 根据direction的值，判断cur的移动方向
    delete cur; // 释放cur指向的内存
    if (direction == false)
        cur = nextCur;
    else
        cur = preCur;
}

// 删除所有的节点（仅保留表头节点）
template<typename T>
void DouList<T>::RemoveAll()
{
    Setbegin(); // 从头开始删除
    int length = GetCount();    //记录当前链表的长度（表头节点除外）
    for (int i = 0; i != length; ++i)
        RemoveThis(false);  // 顺着link方向移动cur
    cur = head;
}

// 置cur于表头节点处
template<typename T>
void DouList<T>::Setbegin()
{
    cur = head;
}

// 获取当前链表的节点个数（不计表头节点）
template<typename T>
int DouList<T>::GetCount()
{
    int count = 0;  // 记录链表长度的变量
    DouListNode<T>* here = cur;
    while (cur->GetLink() != here)    // 遍历整个链表
    {
        ++count;
        cur = cur->GetLink();
    }
    cur = cur->GetLink();   // 整个双向循环链表遍历完成后，置cur到原来的位置
    return count;   // 返回链表长度
}

// 使cur顺着link方向移动
template<typename T>
void DouList<T>::TowardCur()
{
    cur = cur->GetLink();
}

// 使cur顺着prior方向移动
template<typename T>
void DouList<T>::BackCur()
{
    cur = cur->GetPrior();
}

// 返回当前双向循环链表的cur
template<typename T>
DouListNode<T>* DouList<T>::GetCur()
{
    return this->cur;
}

// 返回当前双向循环链表的表头节点
template<typename T>
DouListNode<T>* DouList<T>::GetHead()
{
    return this->head;
}

// 返回当前双向循环链表的表尾节点
template<typename T>
DouListNode<T>* DouList<T>::GetTail()
{
    return this->tail;
}

// 判断链表是否为空
template<typename T>
bool DouList<T>::IsEmpty()
{
    // 链表为空的条件是双向循环链表中只有表头节点（或者等价地说，只有表尾节点）
    return tail->GetLink() == tail;
}

// 向cur指向的节点后，插入一个数据成员为value的新节点
// 当对于空链表执行这个操作时，作用相当于 AddTail(T value)
template<typename T>
void DouList<T>::InsertAfter(T value)
{
    DouListNode<T>* add = new DouListNode<T>(value);    // 创建一个新的链表
    DouListNode<T>* nextCur = cur->GetLink();   // 获得cur的后继结点
    cur->SetLink(add);
    nextCur->SetPrior(add); // 置cur的后继结点的前驱结点，为新创建的节点
    add->SetLink(nextCur);
    add->SetPrior(cur);
    // 当对于空链表执行这个操作时，作用相当于 AddTail(T value)
    if (cur == tail)
        tail = cur->GetLink();
}

// 获取当前cur指向的节点中的数据成员，并将cur沿着link方向移动
template<typename T>
T DouList<T>::GetNext()
{
    // 若当前cur位于表头出，则沿着link顺序移动cur到下一个位置
    if (cur == head)
        cur = cur->GetLink();
    T d = cur->GetData();   // 返回当前节点中的数据
    cur = cur->GetLink();   // 返回数据后，沿着link方向顺序移动cur
    return d;
}

// 获得当前cur指向的节点中的数据成员，并沿着prior方向顺序移动cur
template<typename T>
T DouList<T>::GetPrior()
{
    // 若当前cur位于表头处，则沿着prior方向顺序移动cur到下一个节点
    if (cur == head)
        cur = cur->GetPrior();
    T d = cur->GetData();
    cur = cur->GetPrior();  // 返回数据后，沿着prior方向，顺序移动cur
    return d;
}

