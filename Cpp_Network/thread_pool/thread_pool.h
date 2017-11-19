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
