#include "car.h"

car::car(string license, int i = 0) : license(license), movedTimes(i) {}   // 默认构造函数
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
