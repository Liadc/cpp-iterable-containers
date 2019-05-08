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
        range<T>(const T begin,const T end)
        :_begin(begin),_end(end){}


        class iterator{
            private:
            T curr;
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

        iterator begin() { return range<T>::iterator(_begin); }
        iterator end() { return range<T>::iterator(_end);}

        };

        //    operator T(){
        //         return 
        //     }; //used for itertools::chain, casting.

            // friend std::ostream& operator<<(std::ostream& os, const range& subset);

    
};
