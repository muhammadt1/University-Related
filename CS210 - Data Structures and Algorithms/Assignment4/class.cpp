#include <iostream>
#include "class.h"
using namespace std;

void sorts::insertionSort(int arr[], int n)
{
  for ( int i = 0; i < n; i++) 
  {
    int num1 = arr[i];
    int j = i;

    while (j > 0 && arr[j-1] > arr[i])
    {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = num1;
  }
}



void sorts::MergeSort(int values[], int first, int last)
{
  if (first < last)
  {
    int mid = (first + last)/2;
    MergeSort(values, first, mid);
    MergeSort(values, mid+1, last);

    merge(values,  first, mid, mid + 1, last);

    
  }
}

void sorts:: merge(int values[], int first, int last, int left, int right)
{
  int* tempPtr = new int [left+right];
  int l = left+1;
  int num = 0;

  while (first <= l && l <= last)
  {
    if (values[first] <= values[l])
    {
      tempPtr[num++] = values[first++];
    }
    else
    {
      tempPtr[num++] = values[l++];
    }
  }
  
  while (first <= left)
  {
    tempPtr[num++] = values[first++];
  }

  while (l <= last)
  {
    tempPtr[num++] = values[l++];
  }

  for ( int i = 0; i < num; i++)
  {
    values[first +num] = tempPtr[num];
  }

  delete[]tempPtr;
  
  
}

void sorts::quickSort(int arr[], int first, int last) 
{
  if (first < last) 
  {
    int splitPoint;
    splitPoint = part(arr, first, last);
    quickSort(arr, first, splitPoint - 1);
    quickSort(arr, splitPoint + 1, last);
  }
}


int sorts::part(int arr[], int first, int last)
{
  int split = arr[last];

  int iter = first -1;
  
  for (int i = first; i <= last; i++)
  {
    if (arr[i]<split)
    {
      i++;

      int k = arr[i];
      arr[iter] = arr[i];
      arr[last] = k;

      
    }
  }

  int z = arr[iter+1];
  arr[iter+1] = arr[last];
  arr[last] = z;

  return iter +1;

}



