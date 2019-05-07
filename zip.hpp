#pragma once

#include <iostream>

using namespace std;
using namespace itertools;

template<typename T,typename V> class zip{
    private:
        
    public:
        zip(T a, V b);  //constructor

        T* begin(); //TODO: update this.
        T* end(); //TODO: update this.

        // friend std::ostream& operator<<(std::ostream& os, const zip& subset);

};
