#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace itertools
{
    template <typename T,typename V> class couple; //for returning 

    template <typename T, typename V>
    class zip{ 
        private:
            const T firstContainer;
            const V secondContainer;

        public:
           zip<T,V>(const T a, const V b): firstContainer(a), secondContainer(b){} //constructor
          
            class iterator{ //private inner class. should behave like iterator.
            private:
                decltype(firstContainer.begin()) IT_FirstContainer; //the beginning of the first container.
                decltype(secondContainer.begin()) IT_SecondContainer; //the beginning of the second container.
            public:
                iterator(decltype(firstContainer.begin()) first,decltype(secondContainer.begin()) second):IT_FirstContainer(first),IT_SecondContainer(second){           
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

                bool operator==(const iterator &other) {
                    return IT_FirstContainer == other.IT_FirstContainer;
                }

                bool operator!=(const iterator &other) {
                   return (IT_FirstContainer != other.IT_FirstContainer) && (IT_SecondContainer != other.IT_SecondContainer);
                }

            };

        public:
           //begin and end functions
            iterator begin() const{
            return iterator(firstContainer.begin(),secondContainer.begin());
            }

            iterator end() const{
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

