#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#include "BoardValue.h"

bool isBoardValueValid (char value_in)
{
  if (value_in == BOARD_VALUE_EMPTY || value_in == BOARD_VALUE_BLACK || value_in == BOARD_VALUE_WHITE)
  {
    return true;
  }
  else if (value_in != BOARD_VALUE_EMPTY || value_in != BOARD_VALUE_BLACK || value_in != BOARD_VALUE_WHITE)
  {
    return false;
  }
}
