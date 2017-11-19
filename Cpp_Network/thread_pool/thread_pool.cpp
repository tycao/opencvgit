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
