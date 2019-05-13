#pragma once

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

namespace itertools
{
    template <typename T>
    class powerset
    {
    private: //private of powerset.
        T containerObject;

        class iterator
        {                                    //private inner class. should behave like iterator.
        private:                             //private of iterator.
            typename T::iterator cont_first; //the first element of the container.
            typename T::iterator cont_last;  //the last element of the container.
            size_t totalPowerset;            //the size of the powerset. it will always be 2^(container.size).
            unsigned int indexSubset;        //with indexing, the iterator will know at which place of powerset it is currently iterating over.

        public:                                                                         //public of iterator.
            iterator(typename T::iterator cont_first, typename T::iterator cont_last) : //constructor of iterator inner class.
                                                                                        cont_first(cont_first), cont_last(cont_last), totalPowerset(0), indexSubset(0)
            {
                //we should now compute totalPowerset for initialization. we iterate and counting all elements in the containerObject.
                //then perform 2^(the count).
                size_t countElements = 0;
                typename T::iterator elem_it = cont_first;
                while (elem_it != cont_last)
                { //we iterate the containerObject.  O(1) space.
                    ++countElements;
                    ++elem_it;
                }
                totalPowerset = pow(2, countElements); //totalPowerset is the number of elements inside the powerset, hence 2^container.size
            }

            //operators: to behave like iterator, we need: ++(increment) , *(access) , !=(not equal)
            bool operator!=(iterator const &other) const
            { //not equal, totalPowerset-index is the number of elements left to iterate.
                return ((totalPowerset - indexSubset) != (other.totalPowerset - other.indexSubset - 1));
            }

            iterator &operator++()
            { //++
                ++indexSubset;
                return *this;
            }

            std::set<decltype(*cont_first)> operator*() const //a powerset is a set containig sets. we decided each subset to be std::set.
            {
                set<decltype(*cont_first)> subset;
                typename T::iterator elem_it = cont_first; //element_it is the element-iterator.
                unsigned int i = indexSubset; //current index
                while ( *elem_it != *cont_last && i != 0 ) //not the first element, and the dereferenced element-iterator is different than the last container value,
                { // binary logic, every '1' is an index of an element.
                    unsigned int rem = i % 2; //rem is zero or 1.  1 indicates we need to insert the element into the subset, zero is the end of subset. 
                    //(power of 2, is next subset).
                    i /= 2; // divide i by 2, store in i.
                    if (rem == 1){
                        subset.insert(*elem_it);
                    }
                    ++elem_it;
                }

                return subset;
            }
        };

    public: //public of powerset.
        powerset(const T iterable) : containerObject(iterable) {} //constructor

        iterator begin() const{
            return iterator(containerObject.begin(),containerObject.end());
        }; 
        iterator end()const{
            return iterator(containerObject.end(), containerObject.end());
        };

    }; //powerset class

    //since each subset is a std::set as we decided, we now need to override '<<' operator to fulfill task requirements.
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const std::set<T> &subset)
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