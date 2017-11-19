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
