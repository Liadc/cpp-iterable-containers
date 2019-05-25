#pragma once

// #define DEFINE 

#include <iostream>
#include "zip.hpp"

using namespace std;

namespace itertools {
    template<typename T,typename V> class product{
        private:
            const T firstProduct;
            const V secondProduct;
        public:
            product(const T a, const V b):firstProduct(a),secondProduct(b){}
        class iterator{
            private:
                decltype(firstProduct.begin()) firstItr;
                decltype(firstProduct.end()) firstItr_end;
                decltype(secondProduct.begin()) secondItr;
                decltype(secondProduct.end()) secondItr_end;
                decltype(secondProduct.begin()) secondItrSave;
            public:
                //constructor
                iterator(decltype(firstProduct.begin()) first,decltype(firstProduct.end()) fend,decltype(secondProduct.begin()) second,decltype(secondProduct.end()) send): 
                firstItr(first),secondItrSave(second),secondItr(second),firstItr_end(fend),secondItr_end(send){}

            
                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                iterator& operator ++(){
                    if(secondItr != secondItr_end){
                        if(++secondItr != secondItr_end){
                        }else{
                            if(++firstItr!=firstItr_end){
                            secondItr = secondItrSave;
                            }
                        }
                    }
                    return *this;
                }
                auto operator *(){ //will return a "couple" of the iterators
                    return couple(*firstItr,*secondItr);
                }


                bool operator==(iterator& other) const
                    {
                    return (this->firstItr == other.firstItr && this->secondItr == other.secondItr);
                    }

                bool operator!=(iterator& other) const
                {
                    return !(*this==other);
                }
            };

            //begin and end 
            iterator begin() const{
                return iterator(firstProduct.begin(),firstProduct.end(),secondProduct.begin(),secondProduct.end());
            }
            iterator end() const{
                return iterator(firstProduct.end(),firstProduct.end(),secondProduct.end(),secondProduct.end());
            }
    };
}