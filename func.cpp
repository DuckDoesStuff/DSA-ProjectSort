#include "func.h"

int partition(vector<int> &arr, long long start, long long end, long long &comparison) {
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

void quickSort(vector<int> &arr, long long start, long long end, long long &comparison) {
    if(++comparison && start < end) {
        int pivot = partition(arr, start, end, comparison);;

        quickSort(arr, start, pivot - 1, comparison);
        quickSort(arr, pivot + 1, end, comparison);
    }
}

void bubbleSort(vector<int> &arr, long long n, long long &comparision)
{
    int i, j;
    for (i = 0;++comparision && i < n - 1; i++)
        for (j = 0;++comparision && j < n - i - 1; j++)
            if (++comparision && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}