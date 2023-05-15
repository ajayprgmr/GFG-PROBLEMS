#include<bits/stdc++.h>
using namespace std;

//Solution 1
class Solution {
public:
long long countBits(long long N) {
    long long  int count = 0;
    for (int i = 0; i < 64; i++) {
        count += (N >> i) / 2 * (1LL << i) + max(0LL, (N % (1LL << i)) - (1LL << i-1));
    }
    return count;
}
};

// Solution 2
class Solution {
  public:
    long long countBits(long long N) {
        long long ans=0, i=1, n=N;
        
        while(n!=0){
            long long temp= (N+1)/(2*i);
            ans=ans+temp*i;
            temp= (N+1)/i;
            if(temp%2==1) ans=ans+ (N+1)%i;
            i=i*2;
            n=n>>1;
        }
        return ans;
    }
};