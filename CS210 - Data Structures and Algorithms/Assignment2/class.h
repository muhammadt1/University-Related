#include <iostream>
#include <stack>
using namespace std;

class conv
{
  public:
    int getPredence (char placeHolder );
    string postFix(string inf );
    string spaced(string s);
    void print(string inf);
};