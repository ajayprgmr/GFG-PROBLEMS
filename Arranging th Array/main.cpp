// C++ bruteforce
class Solution {
public:
    void Rearrange(int arr[], int n) {
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                int temp = arr[i];
                
                for (int k = i; k > j; k--) {
                    arr[k] = arr[k-1];
                }
                
                arr[j] = temp;
                j++;
            }
        }
    }
};

// better TC = O(n) SC: O(n)
class Solution {
public:
    void Rearrange(int arr[], int n) {
        int temp[n];
        for(int i=0;i<n;i++)
        temp[i]=arr[i];
        int j=0;
        for(int i=0; i<n; i++) {
            if(temp[i]<0) {
                arr[j]=arr[i];
                j++;
            }
        }
        for(int i=0; i<n; i++) {
            if(temp[i]>=0) {
                arr[j]=temp[i];
                j++;
            }
        }
    }
};

// TC: nlogn and SC: logn
class Solution {
private:
    void merge(int arr[], int low, int mid, int high) {
        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i] >= 0 && arr[j] < 0) {
             rotate(arr + i, arr + j, arr + j + 1);
                i++;
                mid++;
                j++;
            } else {
                i++;
            }
        }
    }

    void mergeSort(int arr[], int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

public:
    void Rearrange(int arr[], int n) {
        mergeSort(arr, 0, n - 1);
    }
};
