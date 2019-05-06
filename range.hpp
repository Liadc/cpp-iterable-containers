#pragma once

#include <iostream>
// #include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

using namespace std;

namespace itertools {
    template<typename T> class range{
        private:
            T firstIncluded;
            T lastExcluded;

        public:
            range(T, T);  //constructor

            T* begin(); //TODO: update this.
            T* end(); //TODO: update this.

            operator T(); //used for itertools::chain

            friend std::ostream& operator<<(std::ostream& os, const range& subset);



    };
};