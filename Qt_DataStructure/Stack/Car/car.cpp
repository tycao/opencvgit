#include "car.h"

car::car(string license, int i = 0) : license(license), movedTimes(i) {}   // Ĭ�Ϲ��캯��
string car::getLicence() const
{
    return license;
}
int car::getMovedTimes() const
{
    return movedTimes;
}
void car::move()
{
    ++movedTimes;
}
car::~car() { }
