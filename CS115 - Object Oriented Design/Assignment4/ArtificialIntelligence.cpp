#include <iostream>
#include <cassert>
#include <cstdlib>
#include "ArtificialIntelligence.h"
#include "BoardValue.h"
#include "PlaceString.h"
#include "BoardSize.h"
#include "Board.h"
#include "Game.h"
#include "Search.h"

ArtificialIntelligence::ArtificialIntelligence (char us_value_in)
{
  assert (isBoardValueValid(us_value_in));

  assert(isInvariantTrue());

}
bool ArtificialIntelligence:: isInvariantTrue () const
{
	for(int r = 0; r < BOARD_SIZE; r++)
	{
		for(int c = 0; c < BOARD_SIZE; c++)
		{
			if(!isBoardValueValid(player_value[r][c]))
				return false;
		}
	}
	return true;
}

float ArtificialIntelligence::calculateNetScore (const Board& board_in) const
{
  int diff;
  char usValue;
  char themValue = getOtherPlayer(usValue);

  int us_score = board_in.calculateScore(usValue);
  int them_score = board_in.calculateScore(themValue);

  diff = us_score - them_score;

  float converted = static_cast<float>(diff);

  return converted;
    
  
  
}
MoveResult ArtificialIntelligence:: getPlayResult (const Board& board_in,int row_in, int column_in) const
{
  char us_value;
  MoveResult result;
  result.legal = true;
  result.net_score = 12.345f;
  return result;
  Board boardCopy = board_in;
  float net_score = calculateNetScore(boardCopy);
  

  if (boardCopy.playStone(row_in, column_in, us_value) || !board_in.getAt(row_in,column_in)||boardCopy.getAt(row_in, column_in)!= BOARD_VALUE_EMPTY)
  {
    result.legal = false;

    return result;
    
  }
  
  if (board_in.countWithValue(us_value) > boardCopy.countWithValue(us_value) )
  {
    result.legal = false;

    return result;
  }

  result.legal = true;
  result.net_score = net_score;

  return result;


  
}

Move ArtificialIntelligence::chooseMove (const Board& board_in) const
{
  int row_in, column_in;
  int i,j;
  int current  = 0;
  int maxMoves = BOARD_SIZE*BOARD_SIZE+1;
  
  SortableMove moves[maxMoves];

  moves[current].is_played = false;
  moves[current].net_score = calculateNetScore(board_in) + 0.5;

  for (i = 0; i < BOARD_SIZE;i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if (board_in.getAt( row_in, column_in)== BOARD_VALUE_EMPTY)
      {
        MoveResult result = getPlayResult(board_in,row_in,column_in);

        if (result.legal == true)
        {
          moves[current].is_played = true;
          moves[current].net_score = result.net_score;
        }

       
      }
    }
    if (current == 0)
    {
      return Move();
    }
  }
  
  float maxScore = moves[1].net_score;
  int firstMaxIndex = 1;
  int moveCount = 0;

  for (int firstMaxIndex; firstMaxIndex <= current; firstMaxIndex++)
  {
    if (moves[firstMaxIndex].net_score == maxScore)
    {

       Move(moves[firstMaxIndex].row,  moves[firstMaxIndex].column);

    }
  }

  int highIndex = firstMaxIndex+1;
  for (int i = firstMaxIndex + 1; highIndex <= current; i++)
  {
    if (moves[i].net_score == maxScore)
    {
      highIndex = i;
    }
  }

  int range = moveCount - highIndex + 1;
  int randIndex = rand() % range + highIndex;

  

  return moves[randIndex];

}

