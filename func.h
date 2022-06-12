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
void quickSortC(vector<int> &arr, long long start, long long end, long long &comparison);
void quickSortT(vector<int> &arr, long long start, long long end);

//bubbleSort functions
void bubbleSortC(vector<int> &arr, long long n, long long &comparision);
void bubbleSortT(vector<int> &arr, long long n);

//insertionSort functions
void insertionSortT(vector<int>& arr, int n);
void insertionSortC(vector<int>& arr, int n, long long &comparison);

//selectionSort functions
void selectionSortC(vector<int> &arr, int n, long long &comp);
void selectionSortT(vector<int> &arr, int n);

//heapSort functions
void heapifyC(vector<int>& arr, int n, int i, long long &comp);
void heapSortC(vector<int>& arr, int n, long long &comp);

void heapifyT(vector<int>& arr, int n, int i);
void heapSortT(vector<int>& arr, int n);

