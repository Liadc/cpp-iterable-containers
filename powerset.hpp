#pragma once

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

namespace itertools
{
    template <typename T>
    class powerset
    {
    private: //private of powerset.
        T containerObject; 

        template <class V>
        class iterator
        { //private inner class. should behave like iterator.
        private:  //private of iterator.
            const V cont_first;             //the first element of the container.
            const V cont_last;              //the last element of the container.
            size_t totalPowerset;     //the size of the powerset. it will always be 2^(container.size).
            unsigned int indexSubset; //with indexing, the iterator will know at which place of powerset it is currently iterating over.

        public: //public of iterator.
            iterator(V contFirst, V contLast) : //constructor of iterator inner class.
                cont_first(contFirst), cont_last(contLast), totalPowerset(0), indexSubset(0)
            {
                //we should now compute totalPowerset for initialization. we iterate and counting all elements in the containerObject.
                //then perform 2^(the count).
                size_t countElements = 0;
                V element_it = cont_first; 
                while (element_it != cont_last)
                { //we iterate the containerObject.  O(1) space.
                    ++countElements;
                    ++element_it;
                }
                totalPowerset = pow(2, countElements); //totalPowerset is the number of elements inside the powerset, hence 2^container.size
            }

            //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
            bool operator!=(iterator<V> const &other) const { //not equal, totalPowerset-index is the number of elements left to iterate.
                return ((totalPowerset - indexSubset) != (other.totalPowerset - other.indexSubset - 1));
            }

            iterator<V> &operator++(){ //++
                ++indexSubset;
                return *this;
            }

            auto operator*() const //a powerset is a set containig sets. we decided each subset to be std::vector.
            {
                std::vector<typename std::remove_const<typename std::remove_reference<decltype(*cont_first)>::type>::type> subset;
                V element_it = cont_first; //element_it is the element-iterator.
                unsigned int i = indexSubset; //current index
                while (element_it != cont_last && i != 0 ) { //not the end of the subset, and i!=0 indicates there still elements need to be inserted.
                    if (i % 2 == 1){ //zero or 1.  1 indicates we need to insert the element into the subset, zero is the end of subset. 
                        subset.emplace_back(*element_it); // since power of 2, is next subset.
                    }
                    i >>= 1; //divides i by 2. using shift-left binary operator.
                    ++element_it;
                }
                return subset;
            }
        };

    public: //public of powerset.
        powerset(const T objIter) : containerObject(objIter) {} //constructor

        auto begin() const {
            return iterator<decltype(containerObject.begin())>(containerObject.begin(),containerObject.end());
        }; 
        auto end() const {
            return iterator<decltype(containerObject.end())>(containerObject.end(), containerObject.end());
        };

    }; //powerset class

    //since each subset is a std::set as we decided, we now need to override '<<' operator to fulfill task requirements.
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &subset)
    {
        os << "{"; //for first subset.
        auto iterator = subset.begin();
        if (iterator != subset.end()){ // first element no comma.
            os << *iterator;
            ++iterator;
        }
        while (iterator != subset.end()){ //between all elements inside subset, insert comma.
            os << ',' << *iterator;
            ++iterator;
        }
        os << "}"; //last closing } for the end of subset.
        return os;
    }
}; // namespace itertools