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

//heapSort functions
void heapifyC(vector<int>& arr, int n, int i,long long &compare) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (++compare&&l < n && ++compare&&arr[l] > arr[largest])
    {
        largest = l;
 	}
    
    if (++compare&&r < n &&++compare&& arr[r] > arr[largest])
    {
        largest = r;
 	}
    
    if (++compare&&largest != i) {
        swap(arr[i], arr[largest]); 
        heapifyC(arr, n, largest,compare);
    }
} 
void heapSortC(vector<int>& arr, int n,long long &compare) {
    for (int i = n / 2 - 1; ++compare&&i >= 0; i--){
        heapifyC(arr, n, i,compare);
    }
 
    for (int i = n - 1;++compare&& i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyC(arr, i, 0,compare);
    }
}

void heapifyT(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyT(arr, n, largest);
    }
}
void heapSortT(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyT(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyT(arr, i, 0);
    }
}

//mergeSort functions
void mergeT(vector<int>& arr, int l, int m, int r) {
    vector<int> leftArr(m-l+1), rightArr(r-m);

    for(int i = l; i < m; i++) 
        leftArr[i - l] = arr[i];
    for(int i = m + 1; i < r; i++)
        rightArr[i - m] = arr[i];

    int left = leftArr.size(), right = rightArr.size();
    int i = 0, j = 0, k = l;
    while(i < left && j < right) {
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while(i < left)
        arr[k++] = leftArr[i++];
    while(j < right)
        arr[k++] = rightArr[j++];
}
void mergeSortT(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int m = l + (r - l)/2;

    mergeSortT(arr, l, m);
    mergeSortT(arr, m + 1, r);
    mergeT(arr, l, m, r);
}

void mergeC(vector<int>& arr, int l, int m, int r, long long &comp) {
    vector<int> leftArr(m-l+1), rightArr(r-m);

    for(int i = l;++comp && i < m; i++) 
        leftArr[i - l] = arr[i];
    for(int i = m + 1;++comp && i < r; i++)
        rightArr[i - m] = arr[i];

    int left = leftArr.size(), right = rightArr.size();
    int i = 0, j = 0, k = l;
    while(++comp && i < left && ++comp && j < right) {
        if(++comp && leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while(++comp && i < left)
        arr[k++] = leftArr[i++];
    while(++comp && j < right)
        arr[k++] = rightArr[j++];
}
void mergeSortC(vector<int>& arr, int l, int r, long long &comp) {
    if(++comp && l >= r) return;
    int m = l + (r - l)/2;

    mergeSortC(arr, l, m, comp);
    mergeSortC(arr, m + 1, r, comp);
    mergeC(arr, l, m, r, comp);
}
