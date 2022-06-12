#include "algoMode.h"

void writeFile(vector<int> &arr, string fileName) {
    ofstream out;
    out.open(fileName);
    int n = arr.size();
    out << n << endl;
    for(int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    out.close();
}

void outputConsole(int time, long long comparison, int output) {
    if(output == 1) cout << "Comparisons: " << comparison << endl;
    else if (output == 2) cout << "Running time: " << time << endl;
    else if (output == 3) {
        cout << "Comparisons: " << comparison << endl;
        cout << "Running time: " << time << endl;
    }
    cout << endl;
}

void outputAlgoName(int algo) {
    string algoName[] = {"Quick sort", "Bubble sort", "Insertion sort", "Heap sort",
                         "Selection sort", "Radix sort", "Merge sort"};
    cout << "Algorithm: " << algoName[algo - 1] << endl;
}

int runAlgoT(int algo, vector<int> &arr) {
    auto start = chrono::high_resolution_clock::now();
    switch (algo)
    {
    case 1:
        quickSortT(arr, 0, arr.size() - 1);
        break;
    case 2:
        bubbleSortT(arr, arr.size());
        break;
    case 3:
        insertionSortT(arr, arr.size());
        break;
    case 4:
        heapSortT(arr, arr.size());
        break;
    case 5:
        selectionSortT(arr, arr.size());
        break;
    case 6://Radix sort
        break;
    case 7:
        mergeSortT(arr, 0, arr.size() - 1);
        break;
    default:
        break;
    }
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return time;
}

void runAlgoCmp(int algo, vector<int> &arr, long long &comparison) {
    switch (algo)
    {
    case 1:
        quickSortC(arr, 0, arr.size() - 1, comparison);
        break;
    case 2:
        bubbleSortC(arr, arr.size(), comparison);
        break;
    case 3:
        insertionSortC(arr, arr.size(), comparison);
        break;
    case 4:
        heapSortC(arr, arr.size(), comparison);
        break;
    case 5:
        selectionSortC(arr, arr.size(), comparison);
        break;
    case 6://Radix sort
        break;
    case 7:
        mergeSortC(arr, 0, arr.size() - 1, comparison);
        break;
    default:
        break;
    }
}

bool isNum(string args) {
    for(int i = 0; i < args.length(); i++)
        if(!isdigit(args[i])) return false;
    return true;
}

int getAlgoName(string args) {
    if(args == "quick-sort")
        return 1;
    else if (args == "bubble-sort")
        return 2;
    else if (args == "insertion-sort")
        return 3;
    else if (args == "heap-sort")
        return 4;
    else if (args == "selection-sort")
        return 5;
    else if (args == "radix-sort")
        return 6;
    else if (args == "merge-sort")
        return 7;
    else return -1;
}

int getDataOrder(string args, int type) {
    if(args == "-rand" || type == 0) {
        cout << "Input order: Randomized" << endl;
        cout << "-----------------------------------" << endl;
        return 0;
    }
    else if (args == "-sorted" || type == 1) {
        cout << "Input order: Sorted" << endl;
        cout << "-----------------------------------" << endl;
        return 1;
    }
    else if (args == "-rev" || type == 2) {
        cout << "Input order: Reversed" << endl;
        cout << "-----------------------------------" << endl;
        return 2;
    }
    else if (args == "-nsorted" || type == 3) {
        cout << "Input order: Nearly sorted" << endl;
        cout << "-----------------------------------" << endl;
        return 3;
    }
    else return -1;
}

int getOutput(string args) {
    if(args == "-comp") return 1;
    else if (args == "-time") return 2;
    else if (args == "-both") return 3;
    else return -1;
}

void algoMode(char* argv[], int &argc) {
    cout << "ALGORITHM MODE" << endl;
    outputAlgoName(getAlgoName(argv[2]));
    bool cmd3 = false;
    vector<vector<int>> arr = makeInput(argv, argc, cmd3);
    if(cmd3) {
        //Command 3
        if (getOutput(argv[4]) == 1)//Output comp
            for(int i = 0; i < 4; i++) {
                getDataOrder("", i);
                long long comparision = 0;
                runAlgoCmp(getAlgoName(argv[2]), arr[i], comparision);

                outputConsole(0, comparision, 1);
            }
        else if (getOutput(argv[4]) == 2)//Output time
            for(int i = 0; i < 4; i++) {
                getDataOrder("", i);
                int time = runAlgoT(getAlgoName(argv[2]), arr[i]);

                outputConsole(time, 0, 2);
            }
        else if (getOutput(argv[argc - 1]) == 3) {//Output both
            vector<vector<int>> arrT = arr;
            int time[4] = {-1};
            long long comp[4] = {0};

            //Measure time
            for(int i = 0; i < 4; i++)
                time[i] = runAlgoT(getAlgoName(argv[2]), arrT[i]);
            //Count comparison
            for(int i = 0; i < 4; i++)
                runAlgoCmp(getAlgoName(argv[2]), arr[i], comp[i]);

            for(int i = 0; i < 4; i++) {
                getDataOrder("", i);
                outputConsole(time[i], comp[i], 3);
            }
        }else {
            cout << "Wrong output type" << endl;
        }
        return;
    }else {
        if(getOutput(argv[argc - 1]) == 1) {//Output comp
            long long comparison = 0;
            runAlgoCmp(getAlgoName(argv[2]), arr[0], comparison);
            outputConsole(0, comparison, 1);
        }else if(getOutput(argv[argc - 1]) == 2) {//Output time
            int time = -1;
            time = runAlgoT(getAlgoName(argv[2]), arr[0]);
            outputConsole(time, 0, 2);
        }else if(getOutput(argv[argc - 1]) == 3) {
            long long comparison = 0;
            int time = -1;
            vector<vector<int>> arrT = arr;
            runAlgoCmp(getAlgoName(argv[2]), arr[0], comparison);
            time = runAlgoT(getAlgoName(argv[2]), arrT[0]);
            outputConsole(time, comparison, 3);
        }else {
            cout << "Wrong output type" << endl;
            return;
        }
    }

    writeFile(arr[0], "output.txt");

    return;
}

vector<int> genNewInput(long long size, int dataOrder) {
    vector<int> arr;
    GenerateData(arr, size, dataOrder);
    return arr;
}

vector<int> readFromPath(char* argv[]) {
    cout << "Input file: " << argv[3] << endl;
    ifstream in;
    in.open(argv[3]);

    string s;
    getline(in, s);

    int n = stoi(s);
    cout << "Input size: " << n << endl;
    cout << "-----------------------------------" << endl;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        getline(in, s, ' ');
        arr.push_back(stoi(s));
    }

    in.close();
    return arr;
}

vector<vector<int>> makeInput(char* argv[], int &argc, bool &flag) {
    vector<vector<int>> arr;
    if (argc == 5) {//Command 1 or Command 3
        if (!isNum(argv[3])) {
            //Command to open file and return an array
            arr.push_back(readFromPath(argv));
        }else {
            flag = true;
            //Command to create 4 arrays
            string fileNames[4] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};
            cout << "Input size: " << argv[3] << endl << endl;
            for(int i = 0; i < 4; i++) {
                arr.push_back(genNewInput(stoi(argv[3]), i));
                writeFile(arr[i], fileNames[i]);
            }
        }
    }else if (argc == 6) {//Command 2
        //Command to create a new array
        cout << "Input size: " << argv[3] << endl;
        int dataOrder = getDataOrder(argv[4], -1);
        arr.push_back(genNewInput(stoi(argv[3]), dataOrder));
        writeFile(arr[0], "input.txt");
    }
    return arr;
}
