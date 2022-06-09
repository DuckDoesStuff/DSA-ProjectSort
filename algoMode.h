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

void writeFile(vector<int> &arr, string fileName);
void outputConsole(int time, int comparison, int output);
void outputAlgoName(int algo);
void runAlgo(int algo, vector<int> &arr, int &comparison);

bool isNum(string args);
int getAlgoName(string args);
int getDataOrder(string args, int type);
int getOutput(string args);

void algoMode(char* argv[], int &argc);

vector<int> genNewInput(int size, int dataOrder);
vector<int> readFromPath(char* argv[]);
vector<vector<int>> makeInput(char* argv[], int &argc, bool &flag);