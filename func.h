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
void quickSortC(vector<int> &arr, int start, int end, long long &comp);
void quickSortT(vector<int> &arr, int start, int end);

//bubbleSort functions
void bubbleSortC(vector<int> &arr, int n, long long &comp);
void bubbleSortT(vector<int> &arr, int n);

//insertionSort functions
void insertionSortT(vector<int>& arr, int n);
void insertionSortC(vector<int>& arr, int n, long long &comp);

//selectionSort functions
void selectionSortC(vector<int> &arr, int n, long long &comp);
void selectionSortT(vector<int> &arr, int n);

//heapSort functions
void heapifyC(vector<int>& arr, int n, int i, long long &comp);
void heapSortC(vector<int>& arr, int n, long long &comp);

void heapifyT(vector<int>& arr, int n, int i);
void heapSortT(vector<int>& arr, int n);

//mergeSort functions
void mergeT(vector<int>& arr, int l, int m, int r);
void mergeSortT(vector<int>& arr, int l, int r);

void mergeC(vector<int>& arr, int l, int m, int r, long long &comp);
void mergeSortC(vector<int>& arr, int l, int r, long long &comp);

//radixSort functions
void radixSortT(vector<int>& arr, int n);
void radixSortC(vector<int>& arr, int n, long long &comp);

//shakerSort functios

