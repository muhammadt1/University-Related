#include <iostream>
#include <iomanip>
#include <climits>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

//Swap integer function
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

//Heaps class
class allHeaps
{
    private:
        void minHeap(int k);
        void maxHeap(int k);
        int parent(int k);
        int parent2(int k);
        int minChild(int k);
        int maxChild(int k);

    public:
        vector <int>array;
        int sizeHeap;
        allHeaps();
        void makeHeap(vector<int>ip);

        int minFind();
        int maxFind();
        void insertToHeap(int v);

        int minDel();
        int maxDel();

};

allHeaps::allHeaps()
{
    sizeHeap = 0;
}

//Function to calculate parent index of a node.
int allHeaps::parent(int k)
{
    int m = (k-1)/2;
    return m;
}

//Function calculate the grandparent index of a node.
int allHeaps::parent2(int k)
{
    int n = parent(parent2(k));
    return n;
}

//Function to find the index of the minimum child.
int allHeaps:: minChild(int k)
{
    int l = 2*k+1;
    int r = 2*k+2;
    int ind;

    if (r < sizeHeap)
    {
        if (array[l] < array[r])
        {
            ind = l;
        }
        else
        {
            ind = r;
        }
       
    }
    else
    {
        ind = l;
    }

    return ind;
}

//Function to find the index of the maximum child
int allHeaps::maxChild(int k)
{
    int l = 2 * k + 1;
    int r = 2 * k + 2;
    int mInd;

    if (r < sizeHeap) 
    {
        if (array[l] > array[r]) 
        {
            mInd = l;
        } 
        else 
        {
            mInd = r;
        }
    } 
    else
    {
        mInd = l;
    }

    return mInd;
}

//function to get the min heap
void allHeaps::minHeap(int k)
{
    int l = 2 * k + 1;
    int r = 2 * k + 2;

    int sm = k;

    if (l < sizeHeap && array[l] < array[k])
    {
        sm = l;
    } 
    if (r < sizeHeap && array[r] < array[sm])
    {
        sm = r;
    }
    if (sm != k)
    {
        swap(array[k],array[sm]);
        minHeap(sm);
    }
}

//function to get the max heap
void allHeaps::maxHeap(int k)
{
    int l = 2 * k + 1;
    int r = 2 * k + 2;

    int lg = k;

    if (l < sizeHeap && array[l] > array[k])
    {
        lg = l;
    }
    if (r < sizeHeap && array[r] > array[lg])
    {
        lg = r;
    }
    if (lg != k) 
    {
        swap(array[k], array[lg]);
        maxHeap(lg);
    }
}

//Function to build the heap from a given array
void allHeaps::makeHeap(vector<int>ip)
{
    array = ip;
    
    for (int i = (array.size()/2) - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            maxHeap(i);
        }
        else
        {
            minHeap(i);
        }
    }
}

//Function to find the minimum value in given heap.
int allHeaps:: minFind()
{
    return array[0];
}

//Function to find the maximum value in given heap.
int allHeaps::maxFind()
{
    return array[1];
}

//Function to insert a value into the heap
void allHeaps::insertToHeap(int v)
{
    array.push_back(v);
    sizeHeap++;

    int s = sizeHeap - 1;
    while (s > 0) 
    {
        int grandparent = parent2(s);
        if ((s % 2 == 0 && array[s] > array[grandparent]) || (s % 2 != 0 && array[s] < array[grandparent])) 
        {
            swap(array[s], array[grandparent]);
            s = grandparent;
        } 
        else 
        {
            break; 
        }
    }
}

//Function to delete the minimum value from heap
int allHeaps::minDel()
{
    if (sizeHeap == 0)
    {
        return INT_MAX;
    }
    int mv= array[0];

    array[0] = array[sizeHeap -1];
    sizeHeap--;
    minHeap(0);
    
    return mv;

}

//Function to delete the maximum value from heap
int allHeaps::maxDel()
{
    if (sizeHeap == 0)
    {
        return INT_MIN;
    }
    int mv = array[0];

    if (sizeHeap == 1)
    {
        sizeHeap--;
        return mv;
    }
    else if (sizeHeap == 2)
    {
        sizeHeap--;
        array[0] = array[1];
    }
    else
    {
        int maxC;
        if (array[3] > array[4])
        {
            maxC = 3;
        }
        else
        {
            maxC = 4;
        }
        array[0] = array[maxC];
        sizeHeap--;
        maxHeap(maxC);
    }
    return mv;
}


int main()
{
    allHeaps heaps;
    int num;
    vector<int> inparr = {6, 81, 87, 14, 17, 12, 28, 71, 25, 80, 20, 52, 78, 31, 42, 31, 59, 16, 24, 79, 63, 18, 19, 32, 13, 15, 48};

    heaps.makeHeap(inparr);

    for (int i = 0; i < inparr.size(); ++i )
    {
        cout << inparr[i];
        if (i < inparr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;  
    
    cout << "Minimum value in the heap is: " << heaps.minFind() << endl;
    cout << "Maximum value in the heap is: " << heaps.maxFind() << endl;

    cout << "Enter a value you want to insert: ";
    cin >> num;
    heaps.insertToHeap(num);

    cout << "Minimum value after insertion is: " << heaps.minFind() << endl;

    int del = heaps.minDel();
    cout << "The minimum value " << del << " has been deleted." << endl;

    cout << endl;

    return 0;
}