#include "Move.h"

bool operator== (const SortableMove& lhs_in, const SortableMove& rhs_in)
{
  if (lhs_in.net_score == rhs_in.net_score)
  {
    return true;
  }
  return false;
}

bool operator< (const SortableMove& lhs_in, const SortableMove& rhs_in)
{
  if (lhs_in.net_score < rhs_in.net_score)
  {
    return true;
  }
  return false;
}



