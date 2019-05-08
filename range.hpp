#pragma once

#include <iostream>

using namespace std;

namespace itertools {
    template<typename T> 
    class range{

        private:
        T begin_;
        T end_;
        public:
        
        class iterator{
            friend class range;
            public:
            T operator*() const {
                 return i_;
            }
                 
            const iterator& operator ++(){ 
                ++i_;
                return *this;
                }

            iterator operator ++(int) { 
                iterator copy(*this);
                ++i_;
                return(copy);
            }

            bool operator ==(const iterator& other) const { return i_ == other.i_;}
            bool operator !=(const iterator& other) const { return i_ != other.i_;}

            protected:
            iterator(T start) : i_ (start){}

            private:
            T i_;
        };

        iterator begin() const { return begin_; }
        iterator end() const { return end_;}
        range(T begin,T end):begin_(begin), end_(end) {}

        };

        //    operator T(){
        //         return 
        //     }; //used for itertools::chain, casting.

            // friend std::ostream& operator<<(std::ostream& os, const range& subset);

    
};
