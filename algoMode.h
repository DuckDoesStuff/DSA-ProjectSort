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

void algoMode(char* argv[], int &argc);

int getDataOrder(string args, int type);
vector<vector<int>> makeInput(char* argv[], int &argc, bool &flag);

int getAlgoName(string args);
void outputAlgoName(int algo);

int runAlgoT(int algo, vector<int> &arr);
void runAlgoCmp(int algo, vector<int> &arr, long long &comparison);

int getOutput(string args);
void outputConsole(int time, long long comparison, int output);

void writeFile(vector<int> &arr, string fileName);

bool isNum(string args);
vector<int> genNewInput(long long size, int dataOrder);
vector<int> readFromPath(char* argv[]);