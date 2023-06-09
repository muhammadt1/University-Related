//
//  main.cpp
//
//  Name: Muhammad Tariq
//  Student Number: 200464392
//

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>

#include "Board.h"
#include "PlaceString.h"
#include "BoardSize.h"
#include "Search.h"
#include "BoardValue.h"

using namespace std;

void printEnd (const string moves_in[], int move_count_in);



int main ()
{
  Board platform;

  boardClear(platform);

  
  
	cout << "Welcome to my Go game!" << endl;
	string name;
	while(name == "")
	{
		cout << "Enter your name:  ";
		getline(cin, name);
	}
	cout << "Hello " << name << ".  You will play black." << endl;
	cout << endl;

	const int MOVE_COUNT_MAX = 1000;
	string moves[MOVE_COUNT_MAX];
	int move_count = 0;

	bool playing = true;
	while(playing)
	{
    
    
		cout << "Enter your move:  ";
		string move_string;
		getline(cin, move_string);

		if(move_string == "quit")
			playing = false;
		else if(move_string == "pass")
		{
			cout << "Black passed" << endl;
			cout << "White passed" << endl;
		}
		else if(isPlaceStringWellFormed(move_string))
		{
			int row    = placeStringToRow   (move_string);
			int column = placeStringToColumn(move_string);
      
      if (isOnBoard(row,column)==0)
      {
        cout << "Forbidden: Place row" <<row<< ", column "<<column<<" is not empty"<< endl;
      }
			if(isOnBoard(row, column))
			{
				cout << "Black played a stone at row " << row << ", column " << column << endl;

				moves[move_count] = move_string;
				move_count++;

				cout << "White passed" << endl;
			}
			else
				cout << "Forbidden: Place row " << row << ", column " << column << " is outside board" << endl;
		}
		else
			cout << "\"" << move_string << "\" is ill-formed." << endl;
		cout << endl;

    
   
    
	}
  boardPrint (platform);
  cout << endl;

  cout << "Black Score: "<<boardCountWithValue(platform, BOARD_VALUE_BLACK);

  cout << "White Score: "<<boardCountWithValue(platform, BOARD_VALUE_WHITE);
  cout << "White was rewarded an additonal 7.5 points: "<<boardCountWithValue(platform, BOARD_VALUE_WHITE) + 7.5;

  if ( boardCountWithValue(platform, BOARD_VALUE_BLACK) > boardCountWithValue(platform, BOARD_VALUE_WHITE))
  {
    cout << "Black won! Finishing with "<< boardCountWithValue(platform, BOARD_VALUE_BLACK)<<endl;
  }
  else if (boardCountWithValue(platform, BOARD_VALUE_BLACK) < boardCountWithValue(platform, BOARD_VALUE_WHITE))
  {
    cout << "White won! Finishing with "<< boardCountWithValue(platform, BOARD_VALUE_WHITE)<<endl;
  }

  
  mySort(moves, move_count);

	cout << endl;
	printEnd(moves, move_count);

	cout << "Goodbye, " << name << "!" << endl;

	return 0;
}

void printEnd (const string moves_in[],int move_count_in)
{
	cout << "Black played " << move_count_in << " stones total" << endl;
	if(move_count_in > 0)
	{
		int smallest = sortedFindSmallest(moves_in, move_count_in);
		int largest  = sortedFindLargest (moves_in, move_count_in);
		int index_K9 = binarySearch(moves_in, move_count_in, "K9");

		cout << "Smallest place was \"" << moves_in[smallest] << "\" (index " << smallest << ")" << endl;
		cout << "Largest place was \""  << moves_in[largest]  << "\" (index " << largest  << ")" << endl;
		if(index_K9 == VALUE_NOT_FOUND)
			cout << "Did not play at \"K9\"" << endl;
		else
			cout << "Did play at \"K9\"" << endl;
	}
}

