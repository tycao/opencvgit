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
