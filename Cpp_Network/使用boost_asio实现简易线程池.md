使用boost::asio实现简易线程池
===========
*boost::asio 作为异步输入输出库，所有的对象都提供了异步调用的函数。* 

### 首先，遇到一个大坑：Qt creator 编译错误 ：cannot find file .pro qt
#### 其实问题的解决办法很简单：就是Qt不支持中文的路径，把源码的路径全部改成英文即可解决问题。首先问题发生在我运行网上的例子程序时，重新构建编译也是出错，提示：
	Cannot find file: F:\Pro\Qt\QT5开发及实例\本书源程序\CH1\CH101\Dialog\Dialog.pro.
	21:55:03: 进程"D:\Qt\Qt5.5.0\5.5\msvc2013_64\bin\qmake.exe"退出，退出代码 2 。
	Error while building/deploying project Dialog (kit: Desktop Qt 5.5.0 MSVC2013 64bit)
	When executing step "qmake"

## QT Creator对大于带有两个空格的目录和中文命名的目录不支持！！
## 究其原因 应该是qmake对带有空格的目录和中文命名的目录不支持！！

### 为了查找这个原因，[我用这里的第二种方式重新编译了boost源码](https://github.com/tycao/learngit/blob/master/Boost_Library_Cpp/boost_compile_method02.md)，可是问题还是出现。然后我就百度寻找问题答案，[在这里找到了答案](http://blog.csdn.net/hyqsong/article/details/47072467)<br />

# 接下来，继续讲解利用boost::asio来进行网络编程
### 程序的目录树如下：
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
    // 构造函数
    ThreadPool(int num);

    // 析构函数
    ~ThreadPool();

    // 成员函数模版必须再类内定义
    // F是一个函数或者函数对象类型， Args是F的形式参数类型
    template<typename F, typename ...Args>
    void post(F&& f, Args&& ...args)
    {
        io_.post(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    }

    // io_service提供的stop()方法，让run()结束进而释放线程资源
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


// 构造函数
ThreadPool::ThreadPool(int num)
    : threadNum_(num),
      stopped_(false),
      work_(io_)
{
    for (int i = 0; i != threadNum_; ++i)
        threads_.push_back(std::make_shared<std::thread>([&](){ io_.run(); }));
        //threads_.push_back(std::shared_ptr<std::thread>(new std::thread([&](){ io_.run(); })));
}

// 析构函数
ThreadPool::~ThreadPool()
{
    stop();
}

// io_service提供的stop()方法，让run()结束进而释放线程资源
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

    // 在 thread 没有被析构之前，调用boost::asio::io_service 的stop()方法
    threads.stop();
}

```

## 程序运行结果如下：
### 第一次运行：
![output01](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output01.png "output01")
### 第二次运行：
![output02](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output02.png "output02")
### 第三次运行：
![output03](https://github.com/tycao/opencvgit/blob/master/Cpp_Network/src/output03.png "output03")