#include <iostream>
#include "range.hpp"

using namespace std;
using namespace itertools;

template <typename T> 
range<T>::range(T a,T b){
    firstIncluded = a;
    lastExcluded = b;
};

template <typename T> 
T* range<T>::begin(){ //TODO
    return firstIncluded;
};

template <typename T> 
T* range<T>::end(){ //TODO
    return lastExcluded;
};