#pragma once


/*
 * class for counted reference semantics
 * - delete the object to which it refers when the last CountedPtr that refers to it is destroyed
*/
template<typename T>
class CountedPtr
{
public:
    explicit CountedPtr(T* p = nullptr)
        : ptr(p),   // ��ʼ��Ϊ��ָ��
          count(new long(1))    // ��ʼ��Ϊ 1
    { }    // �յĺ����� �� �����κβ���

    // �������캯��
    CountedPtr(const CountedPtr<T>& p) noexcept(false)
        : ptr(p.ptr),
          count(p.count)
    {
        ++(*count);
    }

    // ������ֵ�����
    CountedPtr& operator =(const CountedPtr<T>& p)
    {
        // ��ֹ�Ը�ֵ
        if (this != &p)
        {
            dispose();
            ptr = p.ptr;
            count = p.count;
            ++*count;
        }
        return *this;
    }

    // ��������
    ~CountedPtr() noexcept(false)
    {
        dispose();  // ����ǰ����û�б��������������ˣ���С�۵�ǰ���� �Լ� ��Ӧ�����ü���
    }

    // ���� �Զ��������
    T& operator *() const noexcept(false)
    {
        return *this->ptr;
    }

    T* operator ->() const noexcept(false)
    {
        return this->ptr;
    }
private:
    T* ptr;     // ���õĶ���
    long* count;    // ���ü��� �� ������¼һ���������ö��ٴ�

    // �ж����ü����Ƿ�Ϊ0�����ǣ������ٱ����õĶ��� �Լ� ���ü���
    void dispose()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
};
