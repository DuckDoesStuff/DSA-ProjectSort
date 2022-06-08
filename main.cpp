#include <iostream>
#include "func.h"
#include "algoMode.h"
#include "DataGenerator.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(strcmp(argv[1], "-a") == 0) {
        //Run algorithm mode
        algoMode(argv, argc);

    }else if (strcmp(argv[1], "-c") == 0) {
        //Run comparison mode
        // compMode(argv, argc);
    }else cout << "Invalid command!" << endl;






    // vector<int> arr;
    // GenerateData(arr, 100000, 0);
    // ofstream out("inputs\\input.txt");
    // out << "100000" << endl;
    // for(int i = 0; i < 100000; i++) {
    //     out << arr[i] << " ";
    // }
    // out.close();

    system("pause");
    return 0;
}   