#pragma once

#include <string>
using namespace std;

const int INVALID_COORDINATE = -1;

int stringToInteger(const string &str1);
int placeStringToRow(const string &str2);
int placeStringToColumn(const string &str3);
bool isPlaceStringWellFormed(const string &str4);