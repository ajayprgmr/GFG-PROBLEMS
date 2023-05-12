#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
    
         int operations = 0;
        for (int i = 0; i < n; i++) {
              if (arr[i] == 0) {
              continue; // skip zero elements
        }
        
        int j = i;
        
        while (j < n && arr[j] != 0) {
            j++; // find the end of the non-zero subarray
        }
        operations++; // increment operations count for each non-zero subarray
        i = j; // set the next starting index to the end of the current subarray
    }
    return operations;
    }
};
