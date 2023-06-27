#include "Game.h"
#include <iostream>
#include <cassert>
using namespace std;



Game::Game()
{
  
}

Game::Game (const std::string& filename_in)
{
  assert(!filename_in.empty());

  Game(filename);
}

void Game:: printBoard () const
{
  board.print();
}

void Game::printWinner () const
{
  float black_score = board.calculateScore(BOARD_VALUE_BLACK) + 0.0f;
	float white_score = board.calculateScore(BOARD_VALUE_WHITE) + KOMI;
	if(black_score > white_score)
		cout << "Black wins " << black_score << " to " << white_score << " (with komi)" << endl;
	else if(black_score < white_score)
		cout << "White wins " << white_score << " to " << black_score << " (with komi)" << endl;
	else
		cout << "Tie game" << endl;
	cout << endl;
}

const Board& Game:: getBoard () const
{
  return board;
}

bool Game:: whiteAi ()
{
  cout << "White Passed "<<endl;

  return false;
}

void Game::blackPass ()
{
  cout << "Black Passed "<<endl;
}

bool Game:: blackPlay (int row_in, int column_in)
{ 
  
  if(!isOnBoard(row_in, column_in))
  {
    cout << "Forbidden: Place row " << row_in << ", column " << column_in << " is outside board" << endl;

    return false;
  }
  else if(board.getAt(row_in, column_in) == BOARD_VALUE_EMPTY)
  {
    cout << "Forbidden: Place row " << row_in << ", column " << column_in << " is not empty"<< endl;    
    
    return false;
  }
  else
  {
    Board copied = board;
    
    cout << "Black played a stone at row " << row_in << ", column " << column_in << endl;
    
    StonesRemoved removed = copied.playStone(row_in, column_in, BOARD_VALUE_BLACK);
    
    if (BOARD_VALUE_BLACK == 0)
    {
      cout << "Forbidden: Suicide rule" << endl;

      return false;
    }
    else
    {
      board = copied;

      cout << "Black played a stone at row " << row_in << ", column " << column_in << endl;

      printRemoved(removed);

      cout << "White passed" << endl;
      return true;
  
    }
    
		
  }
    
}

void Game::printRemoved (const StonesRemoved& removed_in) const
{
  if(removed_in.them == 1)
		cout << "  Captured " << removed_in.them << " stone" << endl;
	else if(removed_in.them > 1)
		cout << "  Captured " << removed_in.them << " stones" << endl;
	if(removed_in.us == 1)
		cout << "  Lost " << removed_in.us << " stone to suicide" << endl;
	else if(removed_in.us > 1)
		cout << "  Lost " << removed_in.us << " stones to suicide" << endl;
}

