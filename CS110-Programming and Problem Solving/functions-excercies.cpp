//Prompt: Write a program that asks name and then last name of the user, then calls a
//function to print name and last name in 1 line.

#include <iostream>
using namespace std;


void names(string nameOne, string nameTwo);


int main() 
{
  string first, last;
  
  cout << "Enter your first name: ";
  cin >> first;

  cout << "Enter your last name: ";
  cin >> last;

  names(first, last);

  
}

void names(string nameOne, string nameTwo)
{
  cout << "Your full name is "<<nameOne<<nameTwo<<endl;
  
}