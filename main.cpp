#include <iostream>
#include "func.h"
#include "DataGenerator.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(strcmp(argv[1], "-a") == 0) {
        //Run algorithm mode
        algoMode(argv);

    }else if (strcmp(argv[1], "-c") == 0) {
        //Run comparison mode
        compMode(argv);
    }else cout << "Invalid command!" << endl;






    // vector<int> arr;
    // GenerateData(arr, 1000, 0);
    // ofstream out("inputs\\input.txt");
    // out << "1000" << endl;
    // for(int i = 0; i < 1000; i++) {
    //     out << arr[i] << " ";
    // }
    // out.close();

    system("pause");
    return 0;
}   