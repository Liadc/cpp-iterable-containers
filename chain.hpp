#pragma once

#include <iostream>
#include "range.hpp"
// #include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"


using namespace std;
using namespace itertools;

template<typename T,typename V> class chain{ //might be of the form chain< range<char>, string> but iterator should return type char.
    public:
        chain(T a, V b);  //constructor

        T* begin(); //TODO: update this.
        T* end(); //TODO: update this.

        friend std::ostream& operator<<(std::ostream& os, const chain& subset);
    private:

};