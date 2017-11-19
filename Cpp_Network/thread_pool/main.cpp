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
