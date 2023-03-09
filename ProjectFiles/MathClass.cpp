#include "MathClass.h"

MathClass::MathClass(int i)
{
    _value = i;
}

MathClass::~MathClass()
{
}

int MathClass::multiply(int a,int b)
{
    return a * b;
}

void MathClass::increment(void)
{
    _value++;
}

void MathClass::set(int i)
{
    _value = i;
}
