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

        public:
           chain<T,V>(const T a, const V b): firstContainer(a), secondContainer(b){} //constructor
          
            class iterator{ //private inner class. should behave like iterator.
            private:
            typename T::iterator sFirstContainer;
            typename T::iterator eFirstContainer;
            typename V::iterator sSecondIterator;
            public:
                iterator(typename T::iterator _sFirstContainer,typename T::iterator _eFirstContainer,typename V::iterator _sSecondContainer) : 
                sFirstContainer(_sFirstContainer), eFirstContainer(_eFirstContainer),sSecondIterator(_sSecondContainer)
                {} //inline constructor for iter.

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                iterator& operator++() //prefix ++
                {
                    if(sFirstContainer != eFirstContainer){
                         ++sFirstContainer;
                    
                    }else{
                         ++sSecondIterator;
                         
                    }
                    return *this;
                }

                auto operator*()
                {   
                    if(sFirstContainer != eFirstContainer){
                        return *sFirstContainer;
                    }else{
                        return *sSecondIterator;
                    }
                }

                bool operator==(iterator &other) const
                {
                   return (this->sFirstContainer == other.sFirstContainer &&  this->sSecondIterator == other.sSecondIterator);
                }

                bool operator!=(iterator &other) const
                {
                   return !(*this==other);
                }
            };

        public:
           
             typename chain<T,V>::iterator begin()
            {
                return iterator(firstContainer.begin(), firstContainer.end(),secondContainer.begin());
            }

             typename chain<T,V>::iterator end()
            {
                return iterator(firstContainer.end(), firstContainer.end(),secondContainer.end());
            }

            // friend std::ostream& operator<<(std::ostream& os, const chain& subset);
        };    
}; // namespace itertools

