#include "Search.h"
#include <string>
using namespace std;

int linearSearch (const string data_in[], int count_in,const string& value_in)
{
  int i;
  for (i=0; i < count_in; i++)
  {
    if (data_in[i] == value_in)
    {
      return i;
    }
    
  } 
  return VALUE_NOT_FOUND;
  
}
int unsortedFindSmallest (const string data_in[], int count_in)
{
  string minValue = data_in[0];
  int smallestValue = 0;
  int i;

  for (i = 0; i < count_in; i++)
  {
    if (minValue > data_in[i])
    {
      minValue = data_in[i];
    }
  }
  return smallestValue;
}

int unsortedFindLargest (const string data_in[],int count_in)
{
  string maxValue = data_in[0];
  int largestValue = 0;
  int i;

  for (i = 0; i < count_in; i++)
  {
    if (maxValue < data_in[i])
    {
      maxValue = data_in[i];
    }
  }
  return largestValue;
}


