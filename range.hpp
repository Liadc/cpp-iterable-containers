#pragma once

#include <iostream>

using namespace std;

namespace itertools {
    template<class T> 
    class range{
        private:
            T firstIncluded;
            T lastExcluded;

            class iter{ //private inner class. should behave like iterator.
                public:
                    T value;

                    iter(T value) : value(value){}; //inline constructor for iter.

                    //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal) 
                    iter &operator++(){
                        value++;
                        return *this;
                    }
                    
                    T operator*(){
                        return value;
                    }

                    bool operator!=(iter &other){
                        return value != other.value;
                    }
            };

        public:
            range(T a,T b) : firstIncluded(a), lastExcluded(b) {} //inline constructor for range<T>.

            iter begin(){ 
                return iter(firstIncluded);
            }; 

            iter end(){ 
                return iter(lastExcluded);
            };

            operator T(); //used for itertools::chain, casting.

            friend std::ostream& operator<<(std::ostream& os, const range& subset);

    };
};