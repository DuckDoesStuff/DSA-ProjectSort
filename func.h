#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;

void algoMode(char* argv[]);
void compMode(char* argv[]);
vector<int> readFromPath(char* argv[]);

//quickSort functions
int partition(vector<int> &arr, int start, int end);
void quickSort(vector<int> &arr, int start, int end);