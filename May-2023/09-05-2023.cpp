#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  #define MOD 1000000007;
  long long int a, b, c, d;
  
  // function calculate N-th fibonacci
  // number using fast doubling method
  
  void FastDoubling( long long int n, int res[]){
      //Base condition
      
      if(n==0){
          res[0]=0;
          res[1]=1;
          return;
      }
      FastDoubling((n/2), res);
      
      // Here a= F(n)
      a=res[0];
      
      // Here b=F(n+1)
      b=res[1];
      c=2*b-a;
      if(c<0)
      c=c+MOD;
      
      // As F(2n)= F(n)[2F(n+1) -F(n)]
      // here c= F(2n)
      
      c=(a*c)%MOD;
      
      // as F( 2n+1)= F(n)**2 +F(n+1)**2
      // Here d=F(2n+1);
      
      d=(a*a+b*b)%MOD;
      
      // Check if N is odd
      // or even
      
      if(n%2==0){
          res[0]=c;
          res[1]=d;
          
      }
      else{
          res[0]=d;
          res[1]= c+d;
      
  }
  }
    int countStrings(long long int N) {
        // Code here
        int res[2]={0};
        FastDoubling ( N+2, res);
        return res[0];
        
    }
};