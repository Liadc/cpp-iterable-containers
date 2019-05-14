#pragma once

#include <iostream>

using namespace std;

namespace itertools
{
    template <typename T, typename V>
    class chain{ //might be of the form chain< range<char>, string> but iterator should return type char.
        private:

            T firstContainer;
            V secondContainer;
        public:
            template <typename U, typename W>
            class iterator{ //inner class. should behave like iterator.
            private:
                U firstContainerIt; //the iterator for the first container.
                W secondContainerIt; //the iterator for the second container.
                bool keepIteratingFirst; //indicates if we finished iterating the first container. (true = keep iterating first container.)

            public:
                iterator(U iteratable_A, W iteratable_B) : firstContainerIt(iteratable_A), secondContainerIt(iteratable_B), keepIteratingFirst(true) {}

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                iterator& operator++() { //prefix ++
                    if(keepIteratingFirst){ //if we already finished the first iterator
                         ++firstContainerIt;
                    }else{
                         ++secondContainerIt;
                    }
                    return *this;
                }

                auto operator* () const{   
                    if(keepIteratingFirst){ //if we have not finished the first iterator
                        return *firstContainerIt;
                    }else{
                        return *secondContainerIt;
                    }
                }

                bool operator!=(const chain::iterator<U,W> &other){
                    //now check if we finished iterating the first container and should start iterating the second container:
                    if (!(firstContainerIt != other.firstContainerIt)){
                        if(keepIteratingFirst){
                            keepIteratingFirst = false;
                        }
                    }
                    if(keepIteratingFirst){
                        return (firstContainerIt != other.firstContainerIt);
                    }
                    else{
                        return (secondContainerIt != other.secondContainerIt);
                    }
                }
            }; //iterator inner class.

           chain<T,V>(const T a, const V b): firstContainer(a), secondContainer(b){} //constructor

           //begin and end functions
            auto begin() const{
                return iterator<decltype(firstContainer.begin()), decltype(secondContainer.begin())>(firstContainer.begin(), secondContainer.begin());
            }

            auto end() const{
                return iterator<decltype(firstContainer.end()), decltype(secondContainer.end())>(firstContainer.end(), secondContainer.end());
            }

        };    
}; // namespace itertools

