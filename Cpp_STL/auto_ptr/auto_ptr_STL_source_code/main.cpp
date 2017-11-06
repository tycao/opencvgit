#include <iostream>
//#include <memory>

//using namespace std;

/* class auto_ptr
 * - improved standard confirming implementation
*/

namespace Mystd {

    // auxiliary type to enable copies and assignments (now global)
    template<typename Y>
    struct auto_ptr_ref
    {
        Y* yp;
        // ���캯��
        auto_ptr_ref(Y* rhs)
            : yp(rhs)
        { }
    };


    template<typename T>
    class auto_ptr
    {
    public:
        typedef T element_type;

        // constructor ���캯��
        explicit auto_ptr(T* ptr = 0) noexcept    // noexcept : ��֤�����׳��쳣
            : ap(ptr)
        { }

        // copy constructors (with implicit convertion) : �������캯��
        // - note : nonconst parameter ֻ�ܴ��� �ǳ�������
        auto_ptr(auto_ptr& rhs) noexcept    // noexcept : ��֤�����׳��쳣
            : ap(rhs.release())
        { }

        // ��Աģ�溯���� �������캯�� �� ���Խ���ͬ���͵�auto_ptr ����˽������ֵ�� Ϊ��ͬ���͵�auto_ptr
        template<typename Y>
        auto_ptr(auto_ptr<Y>& rhs) noexcept
            : ap(rhs.release())
        { }

        // assignments (with implicit convertion)
        // - note: nonconst parameter
        auto_ptr& operator =(auto_ptr& rhs) noexcept
        {
            reset(rhs.release());
            return *this;
        }

        template<typename Y>
        auto_ptr& operator =(auto_ptr<Y>& rhs) noexcept
        {
            reset(rhs.release());
            return *this;
        }

        // �������� �� destructor
        ~auto_ptr() noexcept
        {
            delete ap;  // �ͷ��ڶ���������Ŀռ���Դ
        }

        // ����auto_ptr������ݳ�Ա�Ľӿ� : value access
        T* get() const noexcept
        {
            return ap;
        }

        T& operator *() const noexcept
        {
            return *ap;
        }

        T* operator ->() const noexcept
        {
            return ap;
        }

        // release ownership
        T* release() noexcept
        {
            T* tmp(ap);
            ap = nullptr;
            return tmp;
        }

        // reset value
        void reset(T* ptr = 0) noexcept
        {
            if (ap != ptr)
            {
                delete ap;
                ap = ptr;
            }
        }

        // special conversions with auxiliary type to enable copies and assignments
        auto_ptr(auto_ptr_ref<T> rhs) noexcept
            : ap(rhs.yp)
        {

        }

        auto_ptr& operator =(auto_ptr_ref<T> rhs) noexcept
        {
            reset(rhs.yp);
            return *this;
        }

        // ��ʽ����ת�� ��auto_ptr<T> -->> auto_ptr_ref<Y>��
        template<typename Y>
        operator auto_ptr_ref<Y>() noexcept
        {
            return auto_ptr_ref<Y>(this->release());
        }

        // ��ʾ����ת���� auto_ptr<T> -->> auto_ptr<Y> ��
        template<typename Y>
        operator auto_ptr<Y>() noexcept
        {
            return auto_ptr<Y>(this->release());
        }
    private:
        T* ap;  // refers to the actual owned object (if any)
    };

    template<typename T>
    std::ostream& operator <<(std::ostream& os, const Mystd::auto_ptr<T>& p)
    {
        // check whether or not p owns an object
        if (p.get() == nullptr)
            os << "NULL";
        else
            os << *p;
        return os;
    }
}



int main(int argc, char *argv[])
{
    Mystd::auto_ptr<int> p(new int(10));
    Mystd::auto_ptr<int> q(new int(100));
    Mystd::auto_ptr<int> r;

    std::cout << "after initialization : \n";
    std::cout << "p : " << p << std::endl;
    std::cout << "q : " << q << std::endl;
    std::cout << "r : " << r << std::endl;

    *q = *p;
    //r = p;

    std::cout << "after assigning values : \n";
    std::cout << "p : " << p << std::endl;
    std::cout << "q : " << q << std::endl;
    std::cout << "r : " << r << std::endl;

    const Mystd::auto_ptr<int> pp(new int(20));
    const Mystd::auto_ptr<int> qq(new int(200));
    const Mystd::auto_ptr<int> rr;

    std::cout << "after initailization: \n";
    std::cout << "pp: " << pp << std::endl;
    std::cout << "qq: " << qq << std::endl;
    std::cout << "rr: " << rr << std::endl;

    //qq = pp;

    return 0;
}
