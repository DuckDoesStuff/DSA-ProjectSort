#pragma Once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <chrono>
#include "DataGenerator.h"
#include "func.h"

using namespace std;

void outputAlgoNameC(int algo);

void runAlgoCCmp(int algo, vector<int> &arr, long long &comparison);

int runAlgoCT(int algo, vector<int> &arr);

int getAlgoNameC(string args);

int getDataOrderC(string args, int type);

void compMode(char* argv[], int &argc);

vector<int> readFromPathC(char* argv[]);