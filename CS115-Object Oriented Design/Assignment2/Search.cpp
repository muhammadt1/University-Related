#include "Search.h"
#include <cassert> 
#include <string>
using namespace std;

int linearSearch (const string data_in[], int count_in, const string& value_in)
{
	for(int i = 0; i < count_in; i++)
	{
		if(data_in[i] == value_in)
			return i;  // end function immediately
	}

	// value not in array
	return VALUE_NOT_FOUND;
}

 int unsortedFindSmallest (const string data_in[], int count_in)
{
	int smallest_index = 0;

	for(int i = 1; i < count_in; i++)
	{
		if(data_in[i] < data_in[smallest_index])
			smallest_index = i;
	}

	return smallest_index;
}

int unsortedFindLargest (const string data_in[], int count_in)
{
	int largest_index = 0;

	for(int i = 1; i < count_in; i++)
	{
		if(data_in[largest_index] < data_in[i])
			largest_index = i;
	}

	return largest_index;
}
//Selection Sort. Algorithim taken from class notes.
void mySort (string data_in[], int count_in)
{
  int i, j, search_min;
  string temp;
  for (i = 0; i < count_in ; i++)
  {
    search_min = i;
    for (j = i+1; j < count_in;j++)
    {
      if (data_in[j] < data_in[search_min])
      {
        search_min = j;
      } 
    }
    temp = data_in[search_min];
    data_in[search_min] = data_in[i];
    data_in[i] = temp;
  }
}
bool isSorted (const string data_in[],int count_in)
{
  int i;
  
  if (count_in < 1)
  {
    return true;
  }
  for (i = 1; i < count_in; i++)
  {
    if (data_in[i]< data_in[i-1])
    {
      return false;
    }
  }
  return true;
  
}
int sortedFindSmallest (const string data_in[], int count_in)
{
  assert(isSorted(data_in, count_in));
  assert(count_in > 0);

  int min = 0, i;  

  for (i = 1; i < count_in; i++)
  {
    if (data_in[i] < data_in[min])
    {
      min = i;
    }
    
    
  }
  return min;
  
}
int sortedFindLargest (const string data_in[], int count_in)
{
  int i;
  int max;
  int count = count_in - 1;
  int sorted = isSorted(data_in, count_in);
  assert(count_in > 0);
  assert (sorted);
  //Do while loop used to test condition once before testing to loop
  do
  {
    if (data_in[count] > data_in[max])
    {
      count = max;
    }
    i--;
  }while (i > 0);

  return max;
  
}
int binarySearch (const string data_in[], int count_in, const string& value_in)
{
  const int NO_SUCH_VALUE = -1;
  int sorted = isSorted(data_in, count_in);
  assert(sorted);

  int low = 0;
  int high = count_in - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (data_in[mid] == value_in)
    {
      return true;
    }
    else if (data_in[mid] > value_in)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return VALUE_NOT_FOUND;
}
//Algorithm taken from notes
int binarySearchFirst (const string data_in[], int count_in, const string& value_in)
{
  const int NO_SUCH_VALUE = -1;
  double sorted = isSorted(data_in, count_in);
  assert(sorted);

  int low = 0;
  int high = count_in - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (data_in[mid] == value_in)
    {
      if (data_in[mid-1] != value_in || mid == 0 )
      {
        return mid;
      }
    }
    if (count_in <= 0)
    {
      return NO_SUCH_VALUE;
    }
    else if (data_in[mid] >= value_in)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return NO_SUCH_VALUE;
}




