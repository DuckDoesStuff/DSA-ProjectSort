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
int partition(vector<int> &arr, long long start, long long end, long long &comparison);
void quickSort(vector<int> &arr, long long start, long long end, long long &comparison);

//bubbleSort functions
void bubbleSort(vector<int> &arr, long long n, long long &comparision);

//insertionSort functions
void insertionSort(vector<int> &arr, long long n, long long &comarison);