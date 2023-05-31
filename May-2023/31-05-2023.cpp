// C++ Solution
#include<bits/stdc++.h>
using namespace std;
// Bruteforce approach O(n^2)
class Solution {
public:
    int LargButMinFreq(int arr[], int n) {
        int max_element = INT_MIN;
        int min_frequency = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int frequency = 0;

            for (int j = 0; j < n; j++) {
                if (num == arr[j]) {
                    frequency++;
                }
            }

            if (frequency < min_frequency) {
                min_frequency = frequency;
                max_element = num;
            }
            else if (frequency == min_frequency) {
                max_element = max(max_element, num);
            }
        }

        return max_element;
    }
};

// solution 2 : using Hashmap [ nlogn]
class Solution {
public:
    int LargButMinFreq(int arr[], int n) {
       
        //Frequency of each element is counted
        map<int,int>mpp;
        for(int i=0;i<n; i++) {
            mpp[arr[i]]++;
        }
      // Finding max element with min frequency
       int maxele=INT_MIN;
       int minfreq=INT_MAX;
      for(auto it=mpp.begin(); it!=mpp.end(); ++it) {
        if(it->second < minfreq){
           maxele= it->first;
           minfreq=it->second;
        }
        else if(it->second == minfreq) {
            maxele=max(maxele,it->first);
        }
        
          
      }

       return maxele;
     }
};