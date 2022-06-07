#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

void GenerateRandomData(vector<int> &a, int n);
void GenerateSortedData(vector<int> &a, int n);
void GenerateReverseData(vector<int> &a, int n);
void GenerateNearlySortedData(vector<int> &a, int n);
void GenerateData(vector<int> &a, int n, int dataType);