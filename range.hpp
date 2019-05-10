#pragma once

#include <iostream>

using namespace std;

namespace itertools {
    template<typename T> 
    class range{

        private:
        T _begin;
        T _end;
        public:
        //constructor
        range<T>(const T begin,const T end)
        :_begin(begin),_end(end){} 

        //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
        class iterator{
            private:
            T curr; //the current iterator.
            public:
            iterator(T element): curr(element){}

            T operator*() const {
                 return curr;
            }
                 
            iterator& operator ++(){ 
                ++curr;
                return *this;
                }

            iterator operator ++(int) { 
                iterator copy(*this);
                ++curr;
                return copy;
            }

            bool operator ==(const iterator& other) const { return curr == other.curr;}
            bool operator !=(const iterator& other) const { return curr != other.curr;}
        };
        //begin and end function, will return the iterator of range<T>
        iterator begin() { return range<T>::iterator(_begin); }
        iterator end() { return range<T>::iterator(_end);}

        };
    
}
