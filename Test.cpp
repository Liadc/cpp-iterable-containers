/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace itertools;

int main() { 
    //tester
      badkan::TestCase tc("Tests");
     tc.setname("Range test");


    //containers:
    range int1 = range(-1,3);
    range int2 = range(6,7);
    range double1 = range(-1.1,3.1);
    range char1 = range('a','d');

    string int1Ans = "-1012";
    string int2Ans = "6";
    string double1Ans = "-1.1-0.11.12.1";
    string char1Ans = "abc";
    string answers[4] = {int1Ans,int2Ans,double1Ans,char1Ans};
    string actualAns = "";
    

    //build answers:
    // for(int i=0;i<4;i++){
    //     for(auto itValue : arr[i]){
    //         actualAns += itValue;
    //     }
    //     tc.CHECK_EQUAL(actualAns,answers[i]);
    //     actualAns = "";
    // }



  
//   tc.CHECK_EQUAL (emptytree.size(), 0)
//   .CHECK_OK    (emptytree.insert(5))
//   .CHECK_EQUAL (emptytree.size(), 1)
//   .CHECK_EQUAL (emptytree.contains(5), true)
//   .CHECK_OK    (emptytree.remove(5))
// //   .CHECK_THROWS(emptytree.remove(5))
//   .CHECK_EQUAL (emptytree.size() ,0)
  
  tc.print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
