/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include <iomanip>
#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable){
 stringstream ostr;
 for(decltype(*(iterable.begin())) i: iterable){
   ostr << i << ",";
 }     
 return ostr.str();
}     
int main() { 
    //tester
      badkan::TestCase tc("Tests");
     tc.setname("Range test");


    //Containers:

        //Ranges:
    range int1 = range(-1,3);
    range int2 = range(6,7);
    range double1 = range(0.1,4.1);
    range char1 = range('a','d');
    string str = string("our test");
        //Chains:
    chain c1 = chain(int1,int2);
    chain c2 = chain(str,char1);
    chain c3 = chain(int1,double1);



    //Answers
      //Range answers:
    string int1Ans = "-1,0,1,2,";
    string int2Ans = "6,";
    string double1Ans = "0.1,1.1,2.1,3.1,";
    string char1Ans = "a,b,c,";

      //Chain answers:

    string c1Ans = "-1,0,1,2,6,";
    string c2Ans = "o,u,r, ,t,e,s,t,a,b,c,";
    // string c3Ans = "";
    //Arrayed Answers
    string rangeAnswerArr[4] = {int1Ans,int2Ans,double1Ans,char1Ans}; 
    string chainAnswerArr[2] = {c1Ans,c2Ans};
      cout<< "before tests" << endl;
      tc.setname("Ranges:")
      .CHECK_EQUAL(iterable_to_string(int1),rangeAnswerArr[0])
      .CHECK_EQUAL(iterable_to_string(int2),rangeAnswerArr[1])
      .CHECK_EQUAL(iterable_to_string(double1),rangeAnswerArr[2])
      .CHECK_EQUAL(iterable_to_string(char1),rangeAnswerArr[3])

      .setname("Chains:")
      .CHECK_EQUAL(iterable_to_string(c1),chainAnswerArr[0])
      // .CHECK_EQUAL(iterable_to_string(c2),chainAnswerArr[1]) //Error
      .CHECK_EQUAL(iterable_to_string(double1),rangeAnswerArr[2])

      .setname("Zips:")
      
      .setname("Products:")
      

      .setname("Powersets:")
      

      .print();

      cout<< "after tests" << endl;
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
