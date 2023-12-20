

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;


//Insertion sort function to sort array range.
void insertionSort(int arr[], int l, int r) 
{
    for (int i = l + 1; i <= r; i++) 
    {
        int k = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > k) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

//mergeFunc function to support the combining of two subarrays
void mergeFunc(int arr[], int temp[], int l, int m, int r) 
{
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++) 
    {
        temp[k] = arr[k];
    }

    for (int k = l; k <= r; k++) 
    {
        if (i > m) 
        {
            arr[k] = temp[j++];
        } 
        else if (j > r) 
        {
            arr[k] = temp[i++];
        } 
        else if (temp[i] <= temp[j]) 
        {
            arr[k] = temp[i++];
        }
        else 
        {
            arr[k] = temp[j++];
        }
    }
}

//mergeSort function to sort array range.
void mergeSort(int arr[], int temp[], int l, int r) 
{
    if (l < r) 
    {
        if (r - l <= 10) 
        {
            insertionSort(arr, l, r);
        } 
        else 
        {
            int m = l + (r - l) / 2;
            mergeSort(arr, temp, l, m);
            mergeSort(arr, temp, m + 1, r);
            mergeFunc(arr, temp, l, m, r);
        }
    }
}

//parting function used to parition quicksort array.
int parting(int arr[], int small, int big) 
{
    int adj = arr[big];
    int i = small - 1;
    for (int j = small; j <= big - 1; j++) 
    {
        if (arr[j] < adj) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[big]);
    return i + 1;
}

// quickSort Function to sort an array between indices low and high with threshold k
void quickSort(int arr[], int low, int high, int k) 
{
    if (low < high) 
    {
        if (high - low <= k) 
        {
            insertionSort(arr, low, high);
        } 
        else 
        {
            int prt = parting(arr, low, high);
            quickSort(arr, low, prt - 1, k);
            quickSort(arr, prt + 1, high, k);
        }
    }
}

int main() 
{
    int num, key;
    cout << "Enter the number of elements to sort: ";
    cin >> num;
    cout << "Enter the value of K for Quick Insertion sort: ";
    cin >> key;

    int originalArray[num];
    int sortedArray[num];
    int tempArray[num];

    auto startTime = chrono::high_resolution_clock::now();
    auto endTime = chrono::high_resolution_clock::now();

    for (int i = 0; i < num; i++) 
    {
        originalArray[i] = rand() % 1000 + 1;
        sortedArray[i] = originalArray[i];
    }
    cout <<endl;

    cout << "Part 1 - Insertion Sort: " << endl;
    cout << "Unsorted array:" << endl;

    for (int i = 0; i < num; i++) 
    {
        cout << originalArray[i] << " ";
    }
    cout <<endl;

    cout << "Sorted array using Insertion Sort:" << endl;

    startTime = chrono::high_resolution_clock::now();
    insertionSort(sortedArray, 0, num - 1);
    endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsedTime = endTime - startTime;

    for (int i = 0; i < num; i++) 
    {
        cout << sortedArray[i] << " ";
    }
    cout <<endl;

    cout << "Run time: " << elapsedTime.count() << " seconds" << endl << endl;

    for (int i = 0; i < num; i++) 
    {
        sortedArray[i] = originalArray[i];
    }
    cout <<endl;


    cout << "Part 2 - Merge Sort: " << endl;
    cout << "Unsorted array:" << endl;

    for (int i = 0; i < num; i++) 
    {
        cout << originalArray[i] << " ";
    }
    cout <<endl;

    cout << "Sorted array using Merge Sort:" << endl;
    startTime = chrono::high_resolution_clock::now();
    
    mergeSort(sortedArray, tempArray, 0, num - 1);

    endTime = chrono::high_resolution_clock::now();
    elapsedTime = endTime - startTime;

    for (int i = 0; i < num; i++) 
    {
        cout << sortedArray[i] << " ";
    }
    cout <<endl;

    cout << "Running time: " << elapsedTime.count();
}
