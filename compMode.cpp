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

int runAlgoC(int algo, vector<int> &arr, long long &comparision) {
    auto start = chrono::high_resolution_clock::now();
    switch (algo)
    {
    case 1:
        quickSort(arr, 0, arr.size() - 1, comparision);
        break;
    case 2:
        bubbleSort(arr, arr.size(), comparision);
        break;
    case 3://Insertion sort
        break;
    case 4://Heap sort
        break;
    case 5://Selection sort
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
    vector<int> arr1;
    if(argc == 5) {
        //Command 4
        arr1 = readFromPathC(argv);
    } else if(argc == 6) {
        //Command 5
        GenerateData(arr1, stoi(argv[4]), getDataOrderC(argv[5], -1));
        writeFileC(arr1, "input.txt");
    }
    vector<int> arr2 = arr1;

    long long comparision1 = 0;
    int time1 = runAlgoC(getAlgoNameC(argv[2]), arr1, comparision1);

    long long comparision2 = 0;
    int time2 = runAlgoC(getAlgoNameC(argv[3]), arr2, comparision2);

    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << comparision1 << " | " << comparision2 << endl;
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