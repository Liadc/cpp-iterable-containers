#pragma once

#include <iostream>
#include "iter.hpp"

using namespace std;

namespace itertools {
    template<class T> 
    class range{
        private:
            T firstIncluded;
            T lastExcluded;

        public:
            range(T a,T b) : firstIncluded(a), lastExcluded(b) {} //inline constructor for range<T>.

            iter<T> begin(){ 
                return iter(firstIncluded);
            }; 

            iter<T> end(){ 
                return iter(lastExcluded);
            };

            // operator T(){
            //     return 
            // }; //used for itertools::chain, casting.

            friend std::ostream& operator<<(std::ostream& os, const range& subset);

    };
};