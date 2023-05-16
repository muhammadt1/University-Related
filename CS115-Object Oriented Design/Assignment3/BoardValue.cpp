//
//  BoardValue.cpp
//

#include "BoardValue.h"

bool isBoardValueValid(char value_in)
{
  switch (value_in)
  {
  case BOARD_VALUE_EMPTY:
  case BOARD_VALUE_BLACK:
  case BOARD_VALUE_WHITE:
  case BOARD_VALUE_MARKED:
    return true;
  default:
    return false;
  }
}

bool isBoardValuePlayer (char value_in)
{
  switch (value_in)
  {
  case BOARD_VALUE_BLACK:
  case BOARD_VALUE_WHITE:
    return true;
  default:
    return false;
  }
  
}
char getOtherPlayer (char player_value_in)
{
  if (player_value_in == BOARD_VALUE_BLACK)
  {
    return BOARD_VALUE_WHITE;
  }
  else if (player_value_in == BOARD_VALUE_WHITE)
  {
    return BOARD_VALUE_BLACK;
  }
  return BOARD_VALUE_EMPTY;
  
}