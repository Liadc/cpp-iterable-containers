#pragma once

// #define DEFINE 

#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
using namespace std;

namespace itertools {
    template<typename T,typename V> class product{
        private:
        T firstProduct;
        V secondProduct;
        public:
        product(T a, V b):firstProduct(a),secondProduct(b){}
        class iterator{
            private:

            typename T::iterator firstItrSave;
            typename T::iterator firstItr;
            typename T::iterator firstItr_end;
            typename V::iterator secondItr;
            typename V::iterator secondItr_end;
            public:
            iterator(typename T::iterator first,typename T::iterator fend,typename V::iterator second,typename V::iterator send): 
            firstItr(first),firstItrSave(first),secondItr(second),firstItr_end(fend),secondItr_end(send){}
                bool operator==(iterator& other) const
                {
                    return (this->firstItr == other.firstItr && this->secondItr == other.secondItr);
                }

                bool operator!=(iterator& other) const
                {
                    return !(*this==other);
                }

            iterator& operator ++(){
                if(firstItr != firstItr_end){
                    if(++firstItr != firstItr_end){
                    }else{
                        if(++secondItr!=secondItr_end){
                        firstItr = firstItrSave;
                        }
                    }
                }
                return *this;
            }
            auto operator *(){
                return couple(*firstItr,*secondItr);
            }
        };


        iterator begin(){
            return product<T,V>::iterator(firstProduct.begin(),firstProduct.end(),secondProduct.begin(),secondProduct.end());
        }
        iterator end(){
            return product<T,V>::iterator(firstProduct.end(),firstProduct.end(),secondProduct.end(),secondProduct.end());
        }

        private:

    };
}