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
string toString(const Iterable& iterable){
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
    range oneChar = range('a','b');
    range hugeRangeCheckBytes = range(0,10000000); //should give max of 8 bytes, or anything below 100bytes will be reasonable.
    //if it takes too much time to compute and construct the object, something is wrong!
    string str = string("our test");
        //Chains:
    chain c1 = chain(int1,int2);
    chain c2 = chain(str,char1);
    chain c3 = chain(int1,double1);

    std::ostringstream zip1, zip2, zip3, zip4, zip5;
      for (auto zipped : zip(range(-1, 1), range(-1, 1)))
        zip1 << zipped << "<>";
      string zip1Ans = "-1,-1<>0,0<>";
      for (auto zipped : zip(range('b','e'), range('a', 'b')))
        zip2 << zipped << "<>";
      string zip2Ans = "b,a<>c,b<>d,c<>";
      for (auto zipped : zip(string("test"), range(0, 3)))
        zip3 << zipped << "<>";
      string zip3Ans = "t,0<>e,1<>s,2<>t,3<>";
      for (auto zipped : zip(zip(range(0,1),range(3,4)), zip(range('a','c'),range('b','d'))))
        zip4 << zipped << "<>";
      string zip4Ans = "0,3,a,b<>";

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
      //tc.setname("Container Sizes: ")
      //Badkan does not have less/greater than function. this is manual test: Container Sizes
      cout << "Size of huge range, in bytes: " << sizeof(hugeRangeCheckBytes) << endl; //should give max of 8 bytes, or anything below 100bytes will be reasonable.
      //also, if it takes too much time to compute and construct the object, something is wrong!
      
      tc.setname("Ranges:")
      .CHECK_EQUAL(toString(int1),rangeAnswerArr[0])
      .CHECK_EQUAL(toString(int2),rangeAnswerArr[1])
      .CHECK_EQUAL(toString(double1),rangeAnswerArr[2])
      .CHECK_EQUAL(toString(char1),rangeAnswerArr[3])
      .CHECK_EQUAL(toString(range('a','b')),string("a,")) //1 char

      .setname("Chains:")
      .CHECK_EQUAL(toString(c1),chainAnswerArr[0])
      .CHECK_EQUAL(toString(c2),chainAnswerArr[1]) 
      .CHECK_EQUAL(toString(chain(oneChar,string("b"))),string("a,b,"))
      .CHECK_EQUAL(toString(chain(chain(oneChar,string("b")),string("c"))),string("a,b,c,")) //chain of chains of ranges (oneChar is range of 1 char)

      .setname("Zips:")
      .CHECK_EQUAL(zip1.str(), zip1Ans)
      .CHECK_EQUAL(zip2.str(), zip2Ans)
      .CHECK_EQUAL(zip3.str(), zip3Ans)
      .CHECK_EQUAL(zip4.str(), zip4Ans) //mixed combinations


      .setname("Products:")


      .setname("Powersets:")
      .CHECK_EQUAL(toString(powerset(range(-3,2))),string("{},{-3},{-2},{-3,-2},{-1},{-3,-1},{-2,-1},{-3,-2,-1},{0},{-3,0},{-2,0},{-3,-2,0},{-1,0},{-3,-1,0},{-2,-1,0},{-3,-2,-1,0},{1},{-3,1},{-2,1},{-3,-2,1},{-1,1},{-3,-1,1},{-2,-1,1},{-3,-2,-1,1},{0,1},{-3,0,1},{-2,0,1},{-3,-2,0,1},{-1,0,1},{-3,-1,0,1},{-2,-1,0,1},{-3,-2,-1,0,1},")) 
      .CHECK_EQUAL(toString(powerset(range(-1.1,2.9))),string("{},{-1.1},{-0.1},{-1.1,-0.1},{0.9},{-1.1,0.9},{-0.1,0.9},{-1.1,-0.1,0.9},{1.9},{-1.1,1.9},{-0.1,1.9},{-1.1,-0.1,1.9},{0.9,1.9},{-1.1,0.9,1.9},{-0.1,0.9,1.9},{-1.1,-0.1,0.9,1.9},"))
      .CHECK_EQUAL(toString(powerset(chain(oneChar,string("b")))),string("{},{a},{b},{a,b},")) //powerset chains
      .CHECK_EQUAL(toString(powerset(powerset(chain(oneChar,string("b"))))),string("{},{a},{b},{a,b},")) //powerset of powerset, of another container

      .print();

      cout<< "After tests: " <<  endl; 
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
