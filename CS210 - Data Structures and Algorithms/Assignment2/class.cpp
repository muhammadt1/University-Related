#include <iostream>
#include <stack>
using namespace std;

#include "class.h"

int conv::getPredence(char placeHolder) {

  if (placeHolder == '*' || placeHolder == '/') {
    return 2;
  }

  else if (placeHolder == '+' || placeHolder == '-') {
    return 1;
  }

  return 0;
}
string conv::postFix(string inf) {
  int i;
  string pst;
  stack<char> operS;

  for (i = 0; i < inf.length(); i++) {
    char ins = inf[i];

    if (ins >= 'A' && ins <= 'Z' || ins >= 'a' && ins <= 'z') 
    {
      pst = pst + ins;
      pst = pst + " ";
    } 
    else if (ins >= '0' && ins <= '9') 
    {
      pst = pst + ins;
      pst = pst + " ";

    } 
    else if (ins == '(') 
    {
      operS.push(ins);
    } 
    else if (ins == ')') 
    {
      while (operS.empty() != true) 
      {
        pst = pst + operS.top();
        pst = pst + " ";

        operS.pop();
      }

      operS.pop();

      if (operS.empty() != true) 
      {
        if (operS.top() == '(') 
        {
          operS.pop();
        }
      }
      else 
      {
        while (!operS.empty() && getPredence(operS.top()) >= getPredence(ins)) 
        {
          pst += operS.top();

          pst = pst + " ";
          operS.pop();
        }
      }
    }
  }

  return pst;
}

string conv::spaced(string s) 
{

  string output;

  int i = 0;

  while (i < s.length()) {
    if (s[i] != ' ') {
      output = output + s[i];
    }
    i++;
  }

  return output;
}

void conv::print(string inf) 
{

  cout << "Infix : " << inf << endl;
  cout << "Postfix: " << postFix(inf) << endl;
}
