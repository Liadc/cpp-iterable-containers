#pragma once

#include <iostream>
#include <string>
#include "range.hpp"

using namespace std;

namespace itertools
{
    template <typename T,typename V> class couple; //for returning 

    template <typename T, typename V>
    class zip{ 
        private:
            T firstContainer;
            V secondContainer;

        public:
           zip<T,V>(const T a, const V b): firstContainer(a), secondContainer(b){} //constructor
          
            class iterator{ //private inner class. should behave like iterator.
            private:
            typename T::iterator IT_FirstContainer; //the beginning of the first container.
            typename V::iterator IT_SecondContainer; //the beginning of the second container.
            public:
            iterator(typename T::iterator first,typename V::iterator second):IT_FirstContainer(first),IT_SecondContainer(second){
                
            }
                

                //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
                iterator& operator++() //prefix ++
                {
                    ++IT_FirstContainer;
                    ++IT_SecondContainer;
                    return *this;
                }

                auto operator*() const //will return a "couple" of T and V
                {   
                    return couple(*IT_FirstContainer,*IT_SecondContainer); 
                }

                bool operator==(iterator &other) const 
                {
                    return IT_FirstContainer == other.IT_FirstContainer;
                }

                bool operator!=(iterator &other) const
                {
                   return !(*this==other);
                }

            };

        public:
           //begin and end functions
            iterator begin()
            {
            return iterator(firstContainer.begin(),secondContainer.begin());
            }

            iterator end()
            {
            return iterator(firstContainer.end(),secondContainer.end());
            }

        };    


        template<typename T,typename V>
        class couple{ //this class will hold 2 items for the iterator to hold.
            private:
                T first;
                V second;
            public:
                couple<T,V>(const T a,const V b): first(a),second(b){}

                friend ostream& operator<<(ostream& os,const couple& cp){
                    os << cp.first << ',' << cp.second;
                    return os;
                }
        };//class couple

}; // namespace itertools

