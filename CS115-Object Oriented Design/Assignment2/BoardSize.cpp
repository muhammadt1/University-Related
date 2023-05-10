#include "BoardSize.h"

bool isOnBoard(int row_in, int column_in)
{
  if (row_in >= 0 && column_in >= 0)
  {
    if (row_in < 19 && column_in < 19)
    {
      return true;
    }
  }
  return false;
}