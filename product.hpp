#pragma once

#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "powerset.hpp"

using namespace std;

namespace itertools {
    template<typename T,typename V> class product{
        public:
        product(T a, V b);  //constructor

        T* begin(); //TODO: update this.
        T* end(); //TODO: update this.

        private:

    };
}