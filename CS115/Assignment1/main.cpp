
#include "BoardSize.h"
#include "PlaceString.h"
#include <iostream>
#include <string>
using namespace std;

string arr[1000];
int track = 0;;

int main()
{
  string name;
  cout << "Welcome to the game of Go!" << endl;

  cout << "What is your name? " << endl;
  getline(cin, name);

  cout << "Hey " << name << "! "
       << "You will play black." << endl;

  int i = 0;
  bool start = true;

  while (start)
  {
    string user;
    cout << "Your move: ";
    getline(cin, user);

    if (user == "quit" || user == "Quit")
    {
      start = false;
    }
    else if (user == "pass" || user == "Pass")
    {
      cout << "Black passed" << endl;
      cout << "White passed" << endl;
    }
    else if (isOnBoard(placeStringToRow(user), placeStringToColumn(user)))
    {
      cout << "Black played a stone at row " << placeStringToRow(user)
           << " and column " << placeStringToColumn(user) << endl;
      arr[track] = user;
      track++;
    }
    else if (placeStringToRow(user) == INVALID_COORDINATE ||
             placeStringToColumn(user) == INVALID_COORDINATE)
    {
      cout << "Forbidden: Place row " << placeStringToRow(user)
           << " and column " << placeStringToColumn(user)
           << " is outside board." << endl;
    }
    else
    {
      cout << user << "is ill-formed" << endl;
    }
  }

  cout << "Team Black has played "<< track << " stones"<<endl;
  if (track > 0)
  {
    string min = arr[0];
    string max = arr[0];
    string user;
    int i;

    for (i = 0; i <= track; i++)
    { 
      if (min > arr[i])
      {
        min = arr[i];
      }
      else 
      {
        max = arr[i];
      }
    }
    cout << "The smallest entry was "<<min<<endl;
    cout << "The largest entry was "<<max<<endl;

    cout << "Enter any of your strings again: ";
    cin >> user;
    cout << endl;
    
    cout << "Was any entry K9: "<<endl;


    if ((placeStringToRow(user), placeStringToColumn(user) == 'K' && (placeStringToRow(user), placeStringToColumn(user) == '9')))
    {
      cout << "K9 was entered"<<endl;
    }
    else 
    {
      cout << "K9 was not entered"<<endl;
    }

  }

  cout << "Goodbye " << name << "!" << endl;
  
}