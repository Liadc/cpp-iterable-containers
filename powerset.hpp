#pragma once

#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
// #include "powerset.hpp"

using namespace std;

namespace itertools{
template<typename T> class powerset{
    public:
        powerset(T a);  //constructor

        T* begin(); //TODO: update this.
        T* end(); //TODO: update this.

        friend std::ostream& operator<<(std::ostream& os, const powerset& subset);
    private:
};
};