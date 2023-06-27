#include <iostream>
using namespace std;

class sorts
{
  public:
  
    void insertionSort(int arr[],int n);
    void MergeSort(int values[], int first, int last);
    void quickSort(int arr[], int first, int last);

  private:
    void merge(int values[], int first, int last, int left, int right);
    int part(int arr[], int first, int last);

    
};