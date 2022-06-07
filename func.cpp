#include "func.h"


void algoMode(char* argv[]) {
    cout << "ALGORITHM MODE" << endl;
    string algoName = argv[2];

    if(algoName == "quick-sort") {
        cout << "Algorithm: Quick sort" << endl;
        vector<int> arr = readFromPath(argv);

        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        cout << "Running time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

        // ofstream out;
        // out.open("outputs\\output.txt");
        // out << arr.size() << endl;
        // for(int i = 0; i < arr.size() - 1; i++) {
        //     out << arr[i] << " ";
        // }
        // out.close();
    }else cout << "Unknown algorithm" << endl;
}

void compMode(char* argv[]) {
    cout << "COMPARE MODE" << endl;
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

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];
    int l = start, r = end - 1;

    while(true) {
        while(arr[l] < pivot && l <= r) {
            l++;
        }
        while(arr[r] > pivot && l <= r) {
            r--;
        }
        if(l >= r) break;
        swap(arr[l], arr[r]);

        l++;
        r--;
    }
    swap(arr[l], arr[end]);
    return l;
}

void quickSort(vector<int> &arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);;

        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
