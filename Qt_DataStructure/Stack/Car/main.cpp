#include <fstream>
#include <stack>
#include <sstream>
#include "car.h"

int main(int argc, char *argv[])
{
    string filename("../data.txt");
    ifstream in(filename);

    if (!in)
    {
        cerr << "Can't open the file" + filename << endl;
        EXIT_FAILURE;
    }
    stack<car*> parking_lot, tempStack;
    car* pcar;
    string license_plate, action;
    // 按行读取数据
    string str;
    while (getline(in, str))    // 获得文本内的每一行信息
    {
        if (!str.empty())
        {
            istringstream text(str);
            text >> license_plate >> action;
            if (action == "arrives")
                if (parking_lot.size() < 5) // 设定停车场只能停5辆车
                {
                    pcar = new car(license_plate, 0);
                    parking_lot.push(pcar);
                }
                else
                    // 当停车场已满时，对新来车辆输出“车辆已满”的信息（然后不做任何操作，循环下一条数据）
                    cout << "Sorry " << license_plate << " , The Lot is fully occupied!" << endl;
            // 对于每个离开的车辆，将相应的元素从栈中删除
            else if (action == "departs")
            {
                while (!parking_lot.empty() && parking_lot.top()->getLicence() != license_plate)
                {
                    tempStack.push(parking_lot.top());
                    parking_lot.top()->move();
                    parking_lot.pop();
                }
                // 输出每辆车的移动情况
                if (parking_lot.top()->getLicence() == license_plate)
                {
                    cout << parking_lot.top()->getLicence() << " was moved "
                         << parking_lot.top()->getMovedTimes() << " times while it was here." << endl;
                    delete parking_lot.top();   // 释放栈中指针所指向的动态内存（对象）
                    parking_lot.pop();  // 删除栈中的指针变量
                }
                else
                    cout << "Exception!" << endl;
                while (!tempStack.empty())
                {
                    parking_lot.push(tempStack.top());
                    tempStack.pop();
                }
            }
            else throw runtime_error("Invalid action for a car!!!");
        }
    }
    // 输出仍然被停在停车场里的车辆
    cout << "\n\nBelow cars are still in the lot:\n\n";
    while (!parking_lot.empty())
    {
        cout << parking_lot.top()->getLicence() << " was moved "
             << parking_lot.top()->getMovedTimes()
             << " times while it was here.\n";
        delete parking_lot.top();
        parking_lot.pop();
    }
    in.close(); // 关闭文件句柄
    return EXIT_SUCCESS;
}
