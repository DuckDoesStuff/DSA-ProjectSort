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

void writeInput(vector<int> arr);
bool isNum(string args);
void algoMode(char* argv[]);
void compMode(char* argv[]);
void genNewInput(vector<int> &arr, int size, char* argv[]);
vector<int> readFromPath(char* argv[]);

//quickSort functions
int partition(vector<int> &arr, int start, int end, int &comparison);
void quickSort(vector<int> &arr, int start, int end, int &comparison);