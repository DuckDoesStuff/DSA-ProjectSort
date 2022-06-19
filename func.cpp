#include "func.h"

//quickSort functions
int partitionC(vector<int> &arr, int l, int r, long long &comp) {
    int pivot = arr[l+(r-l)/2];
    int left = l, right = r;
    while(++comp && left <= right) {
        while(++comp && arr[left] < pivot) left++;
        while(++comp && arr[right] > pivot) right--;
        if(++comp && left <= right) {
            swap(arr[left], arr[right]);
            left++;right--;
        }
    }
    return left;
}
void quickSortC(vector<int> &arr, int l, int r, long long &comp) {
    int p = partitionC(arr, l, r, comp);
    if(++comp && l < p - 1)
        quickSortC(arr, l, p - 1, comp);
    if(++comp && r > p)
        quickSortC(arr, p, r, comp);
}

int partitionT(vector<int> &arr, int l, int r) {
    int pivot = arr[l+(r-l)/2];
    int left = l, right = r;
    while(left <= right) {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right) {
            swap(arr[left], arr[right]);
            left++;right--;
        }
    }
    return left;
}
void quickSortT(vector<int> &arr, int l, int r) {
    int p = partitionT(arr, l, r);
    if(l < p - 1)
        quickSortT(arr, l, p - 1);
    if(r > p)
        quickSortT(arr, p, r);
}

//bubbleSort functions
void bubbleSortC(vector<int> &arr, int n, long long &comp)
{
    int i, j;
    for (i = 0;++comp && i < n - 1; i++)
        for (j = 0;++comp && j < n - i - 1; j++)
            if (++comp && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSortT(vector<int> &arr, int n)
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

void insertionSortC(vector<int>& arr, int n, long long &comp){
    for (int i = 1;++comp && i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        while (++comp && j > 0 && ++comp && arr[j - 1] > temp)
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
void heapifyC(vector<int>& arr, int n, int i,long long &comp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (++comp && l < n && ++comp && arr[l] > arr[largest])
    {
        largest = l;
 	}
    
    if (++comp && r < n && ++comp && arr[r] > arr[largest])
    {
        largest = r;
 	}
    
    if (++comp && largest != i) {
        swap(arr[i], arr[largest]); 
        heapifyC(arr, n, largest, comp);
    }
} 
void heapSortC(vector<int>& arr, int n,long long &comp) {
    for (int i = n / 2 - 1; ++comp && i >= 0; i--){
        heapifyC(arr, n, i, comp);
    }
 
    for (int i = n - 1;++comp && i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyC(arr, i, 0,comp);
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

//radixSort functions
void radixSortT(vector<int>& arr, int n) {
    vector<int> sorted(n, 0);
    int max = arr[0], exp = 1;

    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];

    while(max / exp > 0) {//while we haven't go through every digits
        int count[10] = { 0 };//array to store digit occurences count

        //Count occurences of digits
        for(int i = 0; i < n; i++) 
            count[(arr[i] / exp) % 10]++;
        
        //Our counting array will now show the correct position of digit i
        for(int i = 1; i < 10; i++)
            count[i] += count[i-1];

        //Rearrange our elements based on their digit position
        for(int i = n - 1; i >= 0; i--) {
            sorted[count[(arr[i] / exp) % 10]] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        arr = sorted;//Copy to our array
        exp *= 10;//Increase expotential to sort the next digit
    }
}

void radixSortC(vector<int>& arr, int n, long long &comp) {
    vector<int> sorted(n, 0);
    int max = arr[0], exp = 1;

    for(int i = 1;++comp && i < n; i++)
        if(++comp && arr[i] > max) max = arr[i];

    while(++comp && max / exp > 0) {//while we haven't go through every digits
        int count[10] = { 0 };//array to store digit occurences count

        //Count occurences of digits
        for(int i = 0;++comp && i < n; i++) 
            count[(arr[i] / exp) % 10]++;
        
        //Our counting array will now show the correct position of digit i
        for(int i = 1;++comp && i < 10; i++)
            count[i] += count[i-1];

        //Rearrange our elements based on their digit position
        for(int i = n - 1;++comp && i >= 0; i--) {
            sorted[count[(arr[i] / exp) % 10]] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        arr = sorted;//Copy to our array
        exp *= 10;//Increase expotential to sort the next digit
    }
}

//shellSort functions
void shellSortT(vector<int>& arr, int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) 
        arr[j] = arr[j - interval];
      
      arr[j] = temp;
    }
  }
}

void shellSortC(vector<int>& arr, int n,long long &compare) {	
  for (int interval = n / 2; ++compare && interval > 0; interval /= 2) {
    for (int i = interval;++compare && i < n; i += 1) 
	{
      int temp = arr[i];
      int j;
      for (j = i; ++compare && j >= interval && ++compare && arr[j - interval] > temp; j -= interval)	
        arr[j] = arr[j - interval];
      
      arr[j] = temp;
    } 
  }
}

//countingSort functions
void countingSortT(vector<int>& arr, int n)
{
    int max = 0, min = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void countingSortC(vector<int>& arr, int n, long long &comp)
{
    int max = 0, min = 0;
    for(int i = 0;++comp && i < n; i++) {
        if(++comp && arr[i] > max) max = arr[i];
        if(++comp && arr[i] < min) min = arr[i];
    }
    int range = max - min + 1;

    vector<int> count(range), output(n);
    for (int i = 0;++comp && i <n; i++)
        count[arr[i] - min]++;

    for (int i = 1;++comp && i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1;++comp && i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0;++comp && i < n; i++)
        arr[i] = output[i];
}

//flashSort functions
void flashSortT(vector<int>& arr, int n) {
    int m = int(0.45 * n);
    vector<int> l(m, 0);
    int min = arr[0], max = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

	double c = (double)(m - 1) / (max - min);
    for (int i = 0; i < n; i++) {
        int k = int(c * (arr[i] - min));
        ++l[k];
    }

    for (int i = 1;i < m; i++) {
        l[i] += l[i - 1];
    }

    int hold = arr[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;

    while (move < n - 1) {
        while (j > l[k] - 1) {
            j++;
            k = int(c * (arr[j] - min) );
        }

        flash = arr[j];
        while (j != l[k]) {
            k = int(c* (flash - min));
            hold = arr[t = --l[k]];
            arr[t] = flash;
            flash = hold;
            move++;
        }
    }

    insertionSortT(arr, n);
}

void flashSortC(vector<int>& arr, int n, long long &comp) {
    int m = int(0.45 * n);
    vector<int> l(m, 0);
    int min = arr[0], max = 0;

    for (int i = 0;++comp && i < n; i++) {
        if (++comp && arr[i] < min) min = arr[i];
        if (++comp && arr[i] > max) max = arr[i];
    }

	double c = (double)(m - 1) / (max - min);
    for (int i = 0; ++comp && i < n; i++) {
        int k = int(c * (arr[i] - min));
        ++l[k];
    }

    for (int i = 1; ++comp && i < m; i++) {
        l[i] += l[i - 1];
    }

    int hold = arr[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;

    while (++comp && move < n - 1) {
        while (++comp && j > l[k] - 1) {
            j++;
            k = int(c * (arr[j] - min));
        }

        flash = arr[j];
        while (++comp && j != l[k]) {
            k = int(c * (flash - min));
            hold = arr[t = --l[k]];
            arr[t] = flash;
            flash = hold;
            move++;
        }
    }

    insertionSortC(arr, n, comp);
}

//shakerSort functions
void ShakerSortT(vector<int>& arr, int n) {
    int L = 0;
    int R = n - 1;

    for (int i = L; i < R; i++) {
        for (int j = R; j > i; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
        L++;
        for (int j = L; j < R; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
        R--;
    }
}

void ShakerSortC(vector<int>& arr, int n, long long& comparison) {
    int L = 0;
    int R = n - 1;

    for (int i = L; ++comparison && i < R; i++) {
        for (int j = R; ++comparison && j > i; j--) {
            if (++comparison && arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
        L++;
        for (int j = L; ++comparison && j < R; j++) {
            if (++comparison && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
        R--;
    }
}