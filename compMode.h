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

void outputAlgoName(int algo);

void runAlgo(int algo, vector<int> &arr, int &comparison);

int getAlgoName(string args);

int getDataOrder(string args, int type);

void compMode(char* argv[], int &argc);

vector<int> readFromPath(char* argv[]);