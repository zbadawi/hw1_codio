/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  //populating dat1
  ULListStr dat1;
  dat1.push_back("7");
  dat1.push_front("8");
  dat1.push_back("9");
  dat1.push_front("12");

  //checking dat1 before popping. size:4
  cout << "size before popping: " << dat1.size() << endl; //first test for correct push_back and push_front
 
  //pop_front dat1
  dat1.pop_front();

  //checking dat1 after pop_front once. size:3
  cout << "size after popping front 1: " << dat1.size() << endl;

  //pop_front dat1
  dat1.pop_front();

  //checking dat1 after pop_front again. size:2
  cout << "size after popping front 2: " << dat1.size() << endl; 

  //repopulate with push_back
  dat1.push_back("6");
  dat1.push_back("5");

  //checking dat1 after push_back repopulation. size:4
  cout << "size after pushing back: " << dat1.size() << endl;
  
  //repopulate with push_front
  dat1.push_front("1");
  dat1.push_front("2");

  //checking dat1 after push_back repopulation. size:6
  cout << "size after pushing front: " << dat1.size() << endl;
  
  //pop_back dat1
  dat1.pop_back();

  //checking dat1 after pop_back again. size:5
  cout << "size after popping back: " << dat1.size() << endl; 
  
  //checking back
  cout << "back: " << dat1.back() << endl;

  //checking front
  cout << "front: " << dat1.front()<< endl;

  //checking get (and getvalueat)
  cout << "In location 0: " << dat1.get(0) << endl;
  cout << "In location 1: " << dat1.get(1) << endl;
  cout << "In location 2: " << dat1.get(2) << endl;
  cout << "In location 3: " << dat1.get(3) << endl;
  cout << "In location 4: " << dat1.get(4) << endl;


  //checking set
  dat1.set(0, "1");
  dat1.set(2, "3");
  
  cout << "new location 0: " << dat1.get(0) <<endl;
  cout << "new location 2: " << dat1.get(2) <<endl;
  cout << "unchanged location 1: " << dat1.get(1) <<endl;

  dat1.pop_back();

  dat1.set(4, "8"); //what would set do to empty element
  
  cout << "new location 4: " << dat1.get(4); 

  return 0;
}

