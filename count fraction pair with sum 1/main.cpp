// BruteForce TC: O(N^2)
#include<bits/stdc++.h>
using namespace std;




// Optimal Solution  TC : O(Nlogn) | SC : O(N)
int countFractions(int n, int numerator[], int denominator[]) {
        int ans = 0;
        map<pair<int, int>, int> fr;
        
        for (int i = 0; i < n; i++) {
            int gcd = __gcd(numerator[i], denominator[i]);
            int x = numerator[i] / gcd;
            int y = denominator[i] / gcd;
            int z = y - x;
            
            if (fr.find({z, y}) != fr.end()) 
                ans += fr[{z, y}];
                
             fr[{x, y}]++;  // store the fraction (x/y) frequency
        }
        
        return ans;
    }