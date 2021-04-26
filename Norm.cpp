
#pragma once
#include <iostream>
using namespace std;
template <class T>
class Norm
{
public:

    virtual void absolute()
    {}
    virtual void norm()
    {}
    virtual void set()
    {}
    virtual void set(T a, T b)
    {}
    virtual void set(T a, T b, T c)
    {}
    virtual string get()
    {
        return " ";
    }


};