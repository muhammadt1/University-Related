#include <iostream>
#include <stack>
#include "class.h"
using namespace std;


int main() 
{
  
  string exp;
  conv convert;
  string spacedExp;
  
  cout << "Welcome! "<<endl;
  cout <<endl;

  cout << "Input a infix expression: "<<endl;
  getline (cin, exp);

  spacedExp = convert.spaced(exp);


  convert.print(spacedExp);

  
  
}