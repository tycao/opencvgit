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
    // ���ж�ȡ����
    string str;
    while (getline(in, str))
    {
        if (!str.empty())
        {
            istringstream text(str);
            text >> license_plate >> action;
            if (action == "arrives")
                if (parking_lot.size() < 5) // �趨ͣ����ֻ��ͣ5����
                {
                    pcar = new car(license_plate, 0);
                    parking_lot.push(pcar);
                }
                else
                    // ��ͣ��������ʱ�������������������������������Ϣ��Ȼ�����κβ�����ѭ����һ�����ݣ�
                    cout << "Sorry " << license_plate << " , The Lot is fully occupied!" << endl;
            // ����ÿ���뿪�ĳ���������Ӧ��Ԫ�ش�ջ��ɾ��
            else if (action == "departs")
            {
                while (!parking_lot.empty() && parking_lot.top()->getLicence() != license_plate)
                {
                    tempStack.push(parking_lot.top());
                    parking_lot.top()->move();
                    parking_lot.pop();
                }
                // ���ÿ�������ƶ����
                if (parking_lot.top()->getLicence() == license_plate)
                {
                    cout << parking_lot.top()->getLicence() << " was moved "
                         << parking_lot.top()->getMovedTimes() << " times while it was here." << endl;
                    delete parking_lot.top();   // �ͷ�ջ��ָ����ָ��Ķ�̬�ڴ棨����
                    parking_lot.pop();  // ɾ��ջ�е�ָ�����
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
    // �����Ȼ��ͣ��ͣ������ĳ���
    cout << "\n\nBelow cars are still in the lot:\n\n";
    while (!parking_lot.empty())
    {
        cout << parking_lot.top()->getLicence() << " was moved "
             << parking_lot.top()->getMovedTimes()
             << " times while it was here.\n";
        delete parking_lot.top();
        parking_lot.pop();
    }
    in.close(); // �ر��ļ����
    return EXIT_SUCCESS;
    //return 0;
}
