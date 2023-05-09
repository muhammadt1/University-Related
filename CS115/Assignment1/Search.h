#pragma once

#include <string>
#include <climits>
using namespace std;

const int VALUE_NOT_FOUND = INT_MAX;

int linearSearch (const string data_in[], int count_in,const string& value_in);
int unsortedFindSmallest (const string data_in[], int count_in);
int unsortedFindLargest (const string data_in[],int count_in);


