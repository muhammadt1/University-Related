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

#include "PlaceString.h"
#include "BoardSize.h"
#include "BoardValue.h"
#include "Board.h"
#include "Game.h"

using namespace std;



void printRemoved (const StonesRemoved& removed_in);
void printEnd (const Board& board_in, const string moves_in[],int move_count_in);



int main ()
{
	cout << "Welcome to my Go game!" << endl;
	string name;
	while(name == "")
	{
		cout << "Enter your name:  ";
		getline(cin, name);
	}
	cout << "Hello " << name << ".  You will play black." << endl;
	cout << endl;

  Game game;

	const int MOVE_COUNT_MAX = 1000;
	string moves[MOVE_COUNT_MAX];
	int move_count = 0;

	bool playing = true;
	while(playing)
	{
		game.printBoard();
		cout << "Enter your move:  ";
		string move_string;
		getline(cin, move_string);

		if(move_string == "quit")
			playing = false;
		else if(move_string == "load")
		{
			string filename;
			cout << "Enter the file name:  ";
			getline(cin, filename);
			game = Game(filename);
		}
		else if(move_string == "pass")
		{
      cout << "Black passed" << endl;
    

      if (game.whiteAi())
      {
        playing = false;
        
      }
	
		}
    else if (move_string  == "new")
    {
      game.printWinner();
      Game();
    }
    else if (move_string == "load")
    {
      string filename;
      
      
      
      cout << "Enter desired filename: ";
      getline(cin, filename);

      game = Game(filename);
      game.printWinner();
    }

		else if(isPlaceStringWellFormed(move_string))
		{
			int row    = placeStringToRow   (move_string);
			int column = placeStringToColumn(move_string);

			if(isOnBoard(row, column))
			{
				if(game.blackPlay(row, column))
				{
					cout << "Black played a stone at row " << row << ", column " << column << endl;
					StonesRemoved removed;

		
					cout << "White passed" << endl;
				}
				else
					cout << "Forbidden: Place row " << row << ", column " << column << " is not empty" << endl;
			}
			else
				cout << "Forbidden: Place row " << row << ", column " << column << " is outside board" << endl;
		}
		else
			cout << "\"" << move_string << "\" is ill-formed." << endl;
		cout << endl;
	}

	game.printBoard();
	cout << endl;

	cout << "Goodbye, " << name << "!" << endl;
	return 0;
}




