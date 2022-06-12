#include "func.h"

//quickSort functions
void quickSortC(vector<int> &arr, long long l, long long r, long long &comp) {
	int p = arr[(l + r) / 2];
	int i = l, j = r;

	while (++comp && i < j) {
		while (++comp && arr[i] < p) i++;
		while (++comp && arr[j] > p) j--;
		if (++comp && i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (++comp && i < r) {
		quickSortC(arr, i, r, comp);
	}
	if (++ comp && l < j) {
		quickSortC(arr, l, j, comp);
	}
}

void quickSortT(vector<int> &arr, long long l, long long r) {
	int p = arr[(l + r) / 2];
	int i = l, j = r;

	while (i < j) {
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSortT(arr, i, r);
	}
	if (l < j) {
		quickSortT(arr, l, j);
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
void insertionSortT(vector<int>& arr, int n){
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

void insertionSortC(vector<int>& arr, int n, long long &comparison){
    for (int i = 1;++comparison && i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        while (++comparison && j > 0 && ++comparison && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

//selectionSort functions
void selectionSortC(vector<int> &arr, int n, long long &comp) {
    int i, j, min_idx;
 
    for (i = 0;++comp && i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1;++comp && j < n; j++)
        if (++comp && arr[j] < arr[min_idx])
            min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

void selectionSortT(vector<int> &arr, int n) {
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}
