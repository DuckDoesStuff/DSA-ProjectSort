#include "compMode.h"

void outputAlgoNameC(int algo) {
    string algoName[] = {"Quick sort", "Bubble sort", "Insertion sort", "Heap sort",
                         "Selection sort", "Radix sort", "Merge sort"};
    cout << algoName[algo - 1];
}

void writeFileC(vector<int> &arr, string fileName) {
    ofstream out;
    out.open(fileName);
    int n = arr.size();
    out << n << endl;
    for(int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    out.close();
}

void runAlgoCCmp(int algo, vector<int> &arr, long long &comparision) {
    switch (algo)
    {
    case 1:
        quickSortC(arr, 0, arr.size() - 1, comparision);
        break;
    case 2:
        bubbleSortC(arr, arr.size(), comparision);
        break;
    case 3:
        insertionSortC(arr, arr.size(), comparision);
        break;
    case 4://Heap sort
        break;
    case 5:
        selectionSortC(arr, arr.size(), comparision);
        break;
    case 6://Radix sort
        break;
    case 7://Merge sort
        break;
    default:
        break;
    }
}

int runAlgoCT(int algo, vector<int> &arr) {
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
    case 4://Heap sort
        break;
    case 5:
        selectionSortT(arr, arr.size());
        break;
    case 6://Radix sort
        break;
    case 7://Merge sort
        break;
    default:
        break;
    }
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return time;
}

int getAlgoNameC(string args) {
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

int getDataOrderC(string args, int type) {
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

void compMode(char* argv[], int &argc) {
    cout << "COMPARISON MODE" << endl;
    cout << "Algorithm: "; 
    outputAlgoNameC(getAlgoNameC(argv[2]));
    cout << " | ";
    outputAlgoNameC(getAlgoNameC(argv[3]));
    cout << endl;
    vector<int> arrT1;
    if(argc == 5) {
        //Command 4
        arrT1 = readFromPathC(argv);
    } else if(argc == 6) {
        //Command 5
        GenerateData(arrT1, stoi(argv[4]), getDataOrderC(argv[5], -1));
        writeFileC(arrT1, "input.txt");
    }
    vector<int> arrC1 = arrT1;
    vector<int> arrC2 = arrT1;
    vector<int> arrT2 = arrT1;

    long long comparison1 = 0;
    runAlgoCCmp(getAlgoNameC(argv[2]), arrC1, comparison1);
    int time1 = runAlgoCT(getAlgoNameC(argv[2]), arrT1);

    long long comparison2 = 0;
    runAlgoCCmp(getAlgoNameC(argv[3]), arrC2, comparison2);
    int time2 = runAlgoCT(getAlgoNameC(argv[3]), arrT2);

    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << comparison1 << " | " << comparison2 << endl;
}

vector<int> readFromPathC(char* argv[]) {
    cout << "Input file: " << argv[4] << endl;
    ifstream in;
    in.open(argv[4]);

    string s;
    getline(in, s);

    long long n = stoi(s);
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