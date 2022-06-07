#include "func.h"

void writeInput(vector<int> arr) {
    ofstream out;
    out.open("outputs\\output.txt");
    int n = arr.size();
    out << n << endl;
    for(int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    out.close();
}

bool isNum(string args) {
    for(int i = 0; i < args.length(); i++)
        if(!isdigit(args[i])) return false;
    return true;
}

void algoMode(char* argv[]) {
    cout << "ALGORITHM MODE" << endl;
    string algoName = argv[2];
    string args = argv[3];

    int comparison = 0;
    if(algoName == "quick-sort") {
        cout << "Algorithm: Quick sort" << endl;

        vector<int> arr;
        if(isNum(args))
            genNewInput(arr, stoi(args), argv);
        else 
            arr = readFromPath(argv);

        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1, comparison);
        auto end = chrono::high_resolution_clock::now();

        auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // ofstream out;
        // out.open("outputs\\output.txt");
        // out << arr.size() << endl;
        // for(int i = 0; i < arr.size() - 1; i++) {
        //     out << arr[i] << " ";
        // }
        // out.close();
    }else {
        cout << "Unknown algorithm" << endl;
        return;
    }


    //Output execution time and comparisons count
    if(strcmp(argv[4], "-time") == 0) 
        cout << "Running time: " << time << endl;
    else if (strcmp(argv[4], "-comp") == 0)
        cout << "Comparisons: " << comparison << endl;
    else if (strcmp(argv[4], "-both") == 0) {
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
    }
}

void compMode(char* argv[]) {
    cout << "COMPARE MODE" << endl;
}

void genNewInput(vector<int> &arr, int size, char* argv[]) {
    cout << "Input size: " << size << endl;
    int dataType = 0;
    if (strcmp(argv[4], "-rand") == 0) {
        dataType = 0;
        cout << "Input order: Randomized" << endl;
    }
    else if (strcmp(argv[4], "-sorted") == 0) {
        dataType = 1;
        cout << "Input order: Sorted" << endl;
    }
    else if (strcmp(argv[4], "-rev") == 0) {
        dataType = 2;
        cout << "Input order: Reversed" << endl;
    }
    else if (strcmp(argv[4], "-nsorted") == 0) {
        dataType = 3;
        cout << "Input order: Nearly sorted";
    }
    GenerateData(arr, atoi(argv[3]), dataType);
    writeInput(arr);
}

vector<int> readFromPath(char* argv[]) {
    cout << "Input file: " << argv[3] << endl;
    ifstream in;
    in.open(argv[3]);

    string s;
    getline(in, s);

    int n = stoi(s);
    cout << "Input size: " << n << endl;
    cout << "--------------------------------------------" << endl;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        getline(in, s, ' ');
        arr.push_back(stoi(s));
    }

    in.close();
    return arr;
}

int partition(vector<int> &arr, int start, int end, int &comparison) {
    int pivot = arr[end];
    int l = start, r = end - 1;

    while(++comparison) {
        while(++comparison && arr[l] < pivot && ++comparison && l <= r) {
            l++;
        }
        while(++comparison && arr[r] > pivot && ++comparison && l <= r) {
            r--;
        }
        if(++comparison && l >= r) break;
        swap(arr[l], arr[r]);

        l++;
        r--;
    }
    swap(arr[l], arr[end]);
    return l;
}

void quickSort(vector<int> &arr, int start, int end, int &comparison) {
    if(++comparison && start < end) {
        int pivot = partition(arr, start, end, comparison);;

        quickSort(arr, start, pivot - 1, comparison);
        quickSort(arr, pivot + 1, end, comparison);
    }
}
