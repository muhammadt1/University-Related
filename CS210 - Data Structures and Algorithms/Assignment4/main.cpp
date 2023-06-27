#include <iostream>
#include <ctime>
#include "class.h"
using namespace std;

int main() 
{
  int userNums;
  sorts s;

  cout << "Enter the number of integer elements: ";
  cin >> userNums;

  int newT[userNums];
  cout << "Enter the elements: ";
  for (int i = 0; i < userNums; i++)
  {
    cin >> newT[i];
  }
  cout <<endl;

/*****************************************************************************/

  clock_t timeInsert =clock();
  s.insertionSort(newT,userNums);
  clock_t timeEnd = clock();
  
  cout << "InsertionSort results: ";
  for (int i = 0; i < userNums; i++)
  {
    cout << newT[i]<<" ";
    
  }
  cout << endl;

  cout << "Required Time: "<< (timeEnd - timeInsert)*1000000 / CLOCKS_PER_SEC<<" microseconds "<<endl;



/*****************************************************************************/
  clock_t timeInsertM =clock();
  s.MergeSort(newT,0,userNums-1);
  clock_t timeEndM = clock();

  cout << "MergeSort Results: ";
  for(int i = 0; i < userNums;i++)
  {
    cout << newT[i]<<" ";
  }
  cout << endl;
  
  cout << "Required Time: "<< (timeEndM - timeInsertM)*1000000 / CLOCKS_PER_SEC<<" microseconds "<<endl;

/*****************************************************************************/
  clock_t timeInsertQ =clock();
  s.quickSort(newT,0,userNums-1);
  clock_t timeEndQ= clock();

  cout << "QuickSort Results: ";
  for (int i = 0; i < userNums; i++)
  {
    cout << newT[i]<<" ";
  }
  cout << endl;

  cout << "Required Time: "<< (timeEndQ - timeInsertQ)*1000000 / CLOCKS_PER_SEC<<" microseconds "<<endl;



  
}