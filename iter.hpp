#pragma once

#include <iostream>

using namespace std;

namespace itertools
{
    template <class T>
    class iter
    {
    public:
        T value;

        iter(T value) : value(value){}; //inline constructor for iter.

        //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
        iter &operator++(T)
        {
            value++;
            return *this;
        }

        T operator*()
        {
            return value;
        }

        bool operator!=(iter &other)
        {
            return value != other.value;
        }
    };
} // namespace itertools