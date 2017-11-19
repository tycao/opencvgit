ʹ��boost::asioʵ�ּ����̳߳�
===========
*boost::asio ��Ϊ�첽��������⣬���еĶ����ṩ���첽���õĺ�����* 

### ���ȣ�����һ����ӣ�Qt creator ������� ��cannot find file .pro qt
#### ��ʵ����Ľ���취�ܼ򵥣�����Qt��֧�����ĵ�·������Դ���·��ȫ���ĳ�Ӣ�ļ��ɽ�����⡣�������ⷢ�������������ϵ����ӳ���ʱ�����¹�������Ҳ�ǳ�����ʾ��
	Cannot find file: F:\Pro\Qt\QT5������ʵ��\����Դ����\CH1\CH101\Dialog\Dialog.pro.
	21:55:03: ����"D:\Qt\Qt5.5.0\5.5\msvc2013_64\bin\qmake.exe"�˳����˳����� 2 ��
	Error while building/deploying project Dialog (kit: Desktop Qt 5.5.0 MSVC2013 64bit)
	When executing step "qmake"

## QT Creator�Դ��ڴ��������ո��Ŀ¼������������Ŀ¼��֧�֣���
## ����ԭ�� Ӧ����qmake�Դ��пո��Ŀ¼������������Ŀ¼��֧�֣���

### Ϊ�˲������ԭ��[��������ĵڶ��ַ�ʽ���±�����boostԴ��](https://github.com/tycao/learngit/blob/master/Boost_Library_Cpp/boost_compile_method02.md)���������⻹�ǳ��֡�Ȼ���ҾͰٶ�Ѱ������𰸣�[�������ҵ��˴�](http://blog.csdn.net/hyqsong/article/details/47072467)<br />

# ��������������������boost::asio������������
### �����Ŀ¼�����£�
![thread_pool](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/thread_pool.png "thread_pool")
### thread_pool.h
```cpp
#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <boost/asio.hpp>


using namespace std;
using namespace boost;
using namespace boost::asio;


typedef std::shared_ptr<std::thread> thread_ptr;
typedef std::vector<thread_ptr> vecThread;

class ThreadPool
{
public:
    // ���캯��
    ThreadPool(int num);

    // ��������
    ~ThreadPool();

    // ��Ա����ģ����������ڶ���
    // F��һ���������ߺ����������ͣ� Args��F����ʽ��������
    template<typename F, typename ...Args>
    void post(F&& f, Args&& ...args)
    {
        io_.post(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    }

    // io_service�ṩ��stop()��������run()���������ͷ��߳���Դ
    void stop();
private:
    bool             stopped_;
    vecThread        threads_;
    int              threadNum_;
    asio::io_service io_;
    asio::io_service::work work_;
};

```

### thread_pool.cpp
```cpp
#include "thread_pool.h"


// ���캯��
ThreadPool::ThreadPool(int num)
    : threadNum_(num),
      stopped_(false),
      work_(io_)
{
    for (int i = 0; i != threadNum_; ++i)
        threads_.push_back(std::make_shared<std::thread>([&](){ io_.run(); }));
        //threads_.push_back(std::shared_ptr<std::thread>(new std::thread([&](){ io_.run(); })));
}

// ��������
ThreadPool::~ThreadPool()
{
    stop();
}

// io_service�ṩ��stop()��������run()���������ͷ��߳���Դ
void ThreadPool::stop()
{
    if(!stopped_)
    {
        io_.stop();
        for(auto t : threads_)
            t->join();
        stopped_ = true;
    }
}
```

### main.cpp
```cpp
#include "thread_pool.h"

void test1(int x) {std::cout<<"test 1:"<<x<<std::endl;}
void test2(int y) {std::cout<<"test 2:"<<y<<std::endl;}

class FunctionObject
{
public:
    void operator ()()
    {
        cout << "function object..." << endl;
    }
};

int main()
{
    ThreadPool threads(5);
    threads.post([](){std::cout<<"test 1"<<std::endl;});
    threads.post([](){std::cout<<"test 2"<<std::endl;});
    threads.post(FunctionObject());
    threads.post(test1, 1);
    threads.post(test2, 2);

    std::chrono::milliseconds timespan(11160); // or whatever
    std::this_thread::sleep_for(timespan);
    //std::this_thread::sleep_for(2s);

    // �� thread û�б�����֮ǰ������boost::asio::io_service ��stop()����
    threads.stop();
}

```

## �������н�����£�
### ��һ�����У�
![output01](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output01.png "output01")
### �ڶ������У�
![output02](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output02.png "output02")
### ���������У�
![output03](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output03.png "output03")