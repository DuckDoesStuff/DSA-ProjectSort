#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <chrono>
#include <fstream>
#include "DataGenerator.h"

using namespace std;

//quickSort functions
int partitionC(vector<int> &arr, long long start, long long end, long long &comparison);
void quickSortC(vector<int> &arr, long long start, long long end, long long &comparison);

int partitionT(vector<int> &arr, long long start, long long end);
void quickSortT(vector<int> &arr, long long start, long long end);

//bubbleSort functions
void bubbleSortC(vector<int> &arr, long long n, long long &comparision);
void bubbleSortT(vector<int> &arr, long long n);

//insertionSort functions
