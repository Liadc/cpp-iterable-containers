#pragma once

#include <iostream>
#include "iter.hpp"
#include "range.hpp"

using namespace std;

namespace itertools
{
    template <class T, class V>
    class chain{ //might be of the form chain< range<char>, string> but iterator should return type char.
        private:
            T firstContainer;
            V secondContainer;

            class doubleIter{ //private inner class. should behave like iterator.
            public:
                T value1;
                V value2;
                bool first;

                doubleIter(T value1, V value2) : value1(*value1), value2(*value2), first(true){}; //inline constructor for iter.

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                template <typename E>
                E &operator++()
                {
                    //todo
                }

                template <typename E>
                E operator*()
                {   
                    if(first)
                        return *value1;
                    else{
                        return *value2;
                    }
                }

                template <typename E>
                bool operator!=(E &other)
                {
                    return value1 != other.value1;
                }
            };

        public:
            chain(T a, V b): firstContainer(a), secondContainer(b){} //constructor

            iter<T> begin()
            {
                return doubleIter(firstContainer, secondContainer);
            };

            iter<V> end()
            {
                return doubleIter(firstContainer, secondContainer);
            };

            // friend std::ostream& operator<<(std::ostream& os, const chain& subset);
        };    
}; // namespace itertools

