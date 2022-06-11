#include <iostream>
#include "func.h"
#include "algoMode.h"
#include "compMode.h"
#include "DataGenerator.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(strcmp(argv[1], "-a") == 0) {
        //Run algorithm mode
        algoMode(argv, argc);

    }else if (strcmp(argv[1], "-c") == 0) {
        //Run comparison mode
        compMode(argv, argc);
    }else cout << "Invalid command!" << endl;

    system("pause");
    return 0;
}   