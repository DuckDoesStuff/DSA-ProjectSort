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

void outputConsole(int time, int comparison, int output) {
    if(output == 1) cout << "Comparisons: " << comparison << endl;
    else if (output == 2) cout << "Running time: " << time << endl;
    else if (output == 3) {
        cout << "Comparisons: " << comparison << endl;
        cout << "Running time: " << time << endl;
    }
    cout << endl;
}

void outputAlgoName(int algo) {
    cout << "Algorithm: ";
    switch (algo)
    {
    case 1:
        cout << "Quick sort" << endl;
        break;
    
    default:
        break;
    }
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

bool isNum(string args) {
    for(int i = 0; i < args.length(); i++)
        if(!isdigit(args[i])) return false;
    return true;
}

int getAlgoName(string args) {
    if(args == "quick-sort")
        return 1;
    else return -1;
}

// int getInput(string args) {
//     //If an input size or a file path
//     if (isNum(args)) {
//         return stoi(args);
//     } else {
//     }
// }

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
        for(int i = 0; i < 4; i++) {
            getDataOrder("", i);
            int comparison = 0;
            auto start = chrono::high_resolution_clock::now();
            // quickSort(arr[i], 0, arr[i].size() - 1, comparison);
            runAlgo(getAlgoName(argv[2]), arr[i], comparison);
            auto end = chrono::high_resolution_clock::now();

            auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

            outputConsole(time, comparison, getOutput(argv[4]));
        }
        return;
    }

    int comparison = 0;

    auto start = chrono::high_resolution_clock::now();
    runAlgo(getAlgoName(argv[2]), arr[0], comparison);
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    writeFile(arr[0], "output.txt");

    if (argc == 5) outputConsole(time, comparison, getOutput(argv[4]));
    else if (argc == 6) outputConsole(time, comparison, getOutput(argv[5]));
    return;
}

vector<int> genNewInput(int size, int dataOrder) {
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
            cout << "Input size: " << argv[3] << endl << endl;
            for(int i = 0; i < 4; i++) {
                arr.push_back(genNewInput(stoi(argv[3]), i));
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
