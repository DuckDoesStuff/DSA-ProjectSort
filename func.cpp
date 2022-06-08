#include "func.h"

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
