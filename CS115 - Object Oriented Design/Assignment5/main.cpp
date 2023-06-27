//
//  main.cpp
//
//  Name: Muhammad Tariq
//  Student Number: 200464392
//

#include <cassert>
#include <string>
#include <iostream>

#include "PlaceString.h"
#include "Game.h"

using namespace std;



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
  
  int userMin, userMax;
  while (userMin < BOARD_SIZE_MIN || userMax > BOARD_SIZE_MAX)
  {
    cout << "Please enter a board size minimum: ";
    cin >> userMin;

    cout << "Please enter a board size maximum: ";
    cin >> userMax;

  if (userMin < BOARD_SIZE_MIN || userMax > BOARD_SIZE_MAX)
  {
    cout << "Invalid board size. Please use the following range "<< BOARD_SIZE_MIN << " and "<<BOARD_SIZE_MAX <<endl;
    
  }
  }



	Game game;

	bool playing = true;
	while(playing)
	{
		game.printBoard();
		cout << "Enter your move:  ";
		string move_string;
		getline(cin, move_string);

		if(move_string == "quit")
			playing = false;
		else if(move_string == "new")
		{
			game.printWinner();
			game = Game();
		}
		else if(move_string == "load")
		{
			game.printWinner();

			string filename;
			cout << "Enter the file name:  ";
			getline(cin, filename);
			game = Game(filename);
		}
		else if(move_string == "pass")
		{
			game.blackPass();

			bool is_white_played = game.whiteAi();
			if(is_white_played == false)
				playing = false;
		}
		else if(isPlaceStringWellFormed(move_string))
		{
			int row    = placeStringToRow   (move_string);
			int column = placeStringToColumn(move_string);

			bool result = game.blackPlay(row, column);
			if(result == true)
				game.whiteAi();
			// else failure message is printed by blackPlay
		}
		else
			cout << "\"" << move_string << "\" is ill-formed." << endl;
		cout << endl;
	}

	game.printWinner();
	cout << "Goodbye, " << name << "!" << endl;
	return 0;
}
