#include<bits/stdc++.h>
using namespace std;
// Bruteforce approach 
class Solution {
    public:
    bool ispalindrome(string s, int l, int r) {
    while(l<=r) {
        if(s[l]!=s[r]) return false;
        else {
            l++, r--;
        }
    }
    return true;
}
    public:
    string longestPalin (string S) {
    int N=S.size();
    int start, end;
    int bestlength=INT_MIN;
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            if(ispalindrome(S, i, j)){
               if(j-i+1 > bestlength) {
                bestlength= j-i+1;
                start = i;
                end = j;
               }
            }
        }
    } 
    string res="";
    for(int i=start; i<=end; i++) 
     res=res+S[i];
     return res;
 } 
};
// (n^2) approach
string longestPalin (string S) {

    int N=S.size();
    int start=0, bestlength=1;
    for(int i=1; i<N; i++) {
        // Check for even length palindrome
        int l=i-1, r=i;
        while(l>=0 && r<N && S[l]==S[r]) {
            if(r-l+1>bestlength) {
                bestlength= r-l+1;
                start= l;
            }
            l--, r++;
        }

        // Check for odd length palindrome
        l= i-1, r= i+1;
        while (l>=0 && r<N && S[l]== S[r]) {
            if(r-l+1 > bestlength) {
                bestlength= r-l+1;
                start=l;
            }
            l--;
            r++; 
        }
        return S.substr(start, bestlength);
    }     
};