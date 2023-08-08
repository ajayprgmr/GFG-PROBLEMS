// problem link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
#include<bits/stdc++.h>
using namespace std;
// bruteforce : recursion
class Solution {
public:
    int cutRod(int price[], int n) {
        if (n <= 0) {
            return 0;
        } 
        int maxVal = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int currentVal = price[i] + cutRod(price, n - i - 1);
            maxVal = max(maxVal, currentVal);
        } 
        return maxVal;
    }
};

// using dp (O^2)
class Solution {
public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }

        return dp[n];
    }
};