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
int partition(vector<int> &arr, int start, int end, int &comparison);
void quickSort(vector<int> &arr, int start, int end, int &comparison);