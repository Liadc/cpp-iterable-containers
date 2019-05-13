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
            class iterator{ //inner class. should behave like iterator.
            private:
                decltype(firstContainer.begin()) FirstContainerIt_start; //the beginning of the first container.
                decltype(firstContainer.end()) FirstContainerIt_end; //the end of the first container ( will be used to check if we already ended the first container (by FirstContainerIt_end == FirstContainerIt_end))
                decltype(secondContainer.begin()) SecondContainerIt_start; //the iterator of the SecondContainer

            public:
                iterator(decltype(firstContainer.begin()) _sFirstContainer,decltype(firstContainer.end()) _FirstContainerIt_end,decltype(secondContainer.begin()) _sSecondContainer) : 
                FirstContainerIt_start(_sFirstContainer), FirstContainerIt_end(_FirstContainerIt_end),SecondContainerIt_start(_sSecondContainer)
                {} // constructor

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                iterator& operator++() //prefix ++
                {
                    if(FirstContainerIt_start != FirstContainerIt_end){ //if we already finished the first iterator
                         ++FirstContainerIt_start;
                    
                    }else{
                         ++SecondContainerIt_start;
                         
                    }
                    return *this;
                }

                auto operator* () const
                {   
                    if(FirstContainerIt_start != FirstContainerIt_end){ //if we already finished the first iterator
                        return *FirstContainerIt_start;
                    }else{
                        return *SecondContainerIt_start;
                    }
                }

                bool operator==(iterator &other) const
                {
                   return (this->FirstContainerIt_start == other.FirstContainerIt_start &&  this->SecondContainerIt_start == other.SecondContainerIt_start);
                }

                bool operator!=(iterator &other) const
                {
                   return !(*this==other);
                }
            }; //iterator inner class.

           chain<T,V>(const T a, const V b): firstContainer(a), secondContainer(b){} //constructor

           //begin and end functions
            auto begin()
            {
                return chain<T,V>::iterator(firstContainer.begin(), firstContainer.end(),secondContainer.begin());
            }

            auto end()
            {
                return chain<T,V>::iterator(firstContainer.end(), firstContainer.end(),secondContainer.end());
            }

            // friend std::ostream& operator<<(std::ostream& os, const chain& subset);
        };    
}; // namespace itertools

