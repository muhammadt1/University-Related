#include <string>
using namespace std;
#include "PlaceString.h"

int stringToInteger(const string &str1)
{
  int i = 0, output = 0;

  if (str1.length() == 0)
  {
    return INVALID_COORDINATE;
  }
  while (i < str1.length())
  {
    if (str1[i] < '0' || str1[i] > '9')
    {
      return INVALID_COORDINATE;
    }
    output = output * 10 + (str1[i] - '0');
    i++;
  }

  return output;
}

int placeStringToRow(const string &str2)
{
  if ((str2.empty() && str2.length() > 0) || str2.length() < 2)
  {
    return INVALID_COORDINATE;
  }

  char firstLetter = str2.at(0);
  int numForBoard = stringToInteger(str2.substr(1));

  if ((firstLetter < 'A') || (firstLetter > 'Z'))
  {
    return INVALID_COORDINATE;
  }

  return numForBoard;
}

int placeStringToColumn(const string &str3)
{
  char ans = str3[0] - 'A';

  if (str3.length() == 0 || str3[0] == 'I' || str3[0] == 'O')
  {
    return INVALID_COORDINATE;
  }
  if (str3[0] >= 'A' && str3[0] <= 'Z')
  {
    return ans;
  }
  else
  {
    return INVALID_COORDINATE;
  }
}

bool isPlaceStringWellFormed(const string &str4)
{
  if (placeStringToRow(str4) == INVALID_COORDINATE ||
      placeStringToColumn(str4) == INVALID_COORDINATE)
  {
    return false;
  }
  return true;
}
