#include "func.h"

//quickSort functions
int partitionC(vector<int> &arr, long long start, long long end, long long &comparison) {
    int pivot = arr[(end + start) / 2];
    int l = start, r = end;

    while(true) {
        //Looking for value > than pivot but on the left side
        while(++comparison && arr[l] < pivot) {
            l++;
        }
        //Looking for value < than pivot but on the right side
        while(++comparison && arr[r] > pivot) {
            r--;
        }
        if(++comparison && l > r) break;
        //Swap the two values found
        swap(arr[l], arr[r]);

        l++;
        r--;
    }
    // swap(arr[l], arr[end]);//use this when pivot is the last element
    return l;
}

void quickSortC(vector<int> &arr, long long start, long long end, long long &comparison) {
    if(++comparison && start < end) {
        int pivot = partitionC(arr, start, end, comparison);

        quickSortC(arr, start, pivot - 1, comparison);
        quickSortC(arr, pivot + 1, end, comparison);
    }
}

int partitionT(vector<int> &arr, long long start, long long end) {
    int pivot = arr[(end + start) / 2];
    int l = start, r = end;

    while(true) {
        //Looking for value > than pivot but on the left side
        while(arr[l] < pivot) {
            l++;
        }
        //Looking for value < than pivot but on the right side
        while(arr[r] > pivot) {
            r--;
        }
        if(l > r) break;
        //Swap the two values found
        swap(arr[l], arr[r]);

        l++;
        r--;
    }
    // swap(arr[l], arr[end]);//use this when pivot is the last element
    return l;
}

void quickSortT(vector<int> &arr, long long start, long long end) {
    if(start < end) {
        int pivot = partitionT(arr, start, end);

        quickSortT(arr, start, pivot - 1);
        quickSortT(arr, pivot + 1, end);
    }
}


//bubbleSort functions
void bubbleSortC(vector<int> &arr, long long n, long long &comparision)
{
    int i, j;
    for (i = 0;++comparision && i < n - 1; i++)
        for (j = 0;++comparision && j < n - i - 1; j++)
            if (++comparision && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSortT(vector<int> &arr, long long n)
{
    int i, j;
    for (i = 0;i < n - 1; i++)
        for (j = 0;j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}


//insertionSort functions
