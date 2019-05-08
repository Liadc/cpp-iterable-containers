#pragma once

#include <iostream>
#include "range.hpp"

using namespace std;

namespace itertools
{
    template <typename T, typename V>
    class chain{ //might be of the form chain< range<char>, string> but iterator should return type char.
        private:
            T firstContainer;
            V secondContainer;

            class doubleIter{ //private inner class. should behave like iterator.
            public:
            typename T::iterator startFirstContainer;
            typename T::iterator endFirstContainer;
            typename V::iterator startSecondIterator;

                doubleIter(typename T::iterator value1,typename T::iterator value2,typename V::iterator value3) : 
                startFirstContainer(value1), endFirstContainer(value2),startSecondIterator(value3)
                {} //inline constructor for iter.

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                template <typename E>
                E &operator++()
                {
                    
                }

                template <typename E>
                E operator*()
                {   

                }

                template <typename E>
                bool operator!=(E &other)
                {
                   
                }
            };

        public:
            chain(T a, V b): firstContainer(a), secondContainer(b){} //constructor
            
             doubleIter<T> typename begin()
            {
                return doubleIter(firstContainer.begin(), firstContainer.end(),secondContainer.begin());
            }

             doubleIter<V> typename end()
            {
                return doubleIter(firstContainer.end(), firstContainer.end(),secondContainer.end());
            }

            // friend std::ostream& operator<<(std::ostream& os, const chain& subset);
        };    
}; // namespace itertools

