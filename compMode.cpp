#include "compMode.h"

void outputAlgoName(int algo) {
    switch (algo)
    {
    case 1:
        cout << "Quick sort";
        break;  
    default:
        break;
    }
}

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

void runAlgo(int algo, vector<int> &arr, int &comparison) {
    switch (algo)
    {
    case 1:
        quickSort(arr, 0, arr.size() - 1, comparison);
        break;
    default:
        break;
    }
}

int getAlgoName(string args) {
    if(args == "quick-sort")
        return 1;
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

void compMode(char* argv[], int &argc) {
    cout << "COMPARISON MODE" << endl;
    cout << "Algorithm: "; 
    outputAlgoName(getAlgoName(argv[2]));
    cout << " | ";
    outputAlgoName(getAlgoName(argv[3]));
    cout << endl;
    vector<int> arr1;
    if(argc == 5) {
        //Command 4
        arr1 = readFromPath(argv);
    } else if(argc == 6) {
        //Command 5
        GenerateData(arr1, stoi(argv[4]), getDataOrder(argv[5], -1));
        writeFile(arr1, "input.txt");
    }
    vector<int> arr2 = arr1;

    int comparision1 = 0;
    auto start1 = chrono::high_resolution_clock::now();
    runAlgo(getAlgoName(argv[2]), arr1, comparision1);
    auto end1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

    int comparision2 = 0;
    auto start2 = chrono::high_resolution_clock::now();
    runAlgo(getAlgoName(argv[3]), arr2, comparision2);
    auto end2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << comparision1 << " | " << comparision2 << endl;
}

vector<int> readFromPath(char* argv[]) {
    cout << "Input file: " << argv[4] << endl;
    ifstream in;
    in.open(argv[4]);

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