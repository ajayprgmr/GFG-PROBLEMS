// C++ solution
class Solution {
  public:
    int getMaximum(int N, vector<int> &arr) {
      int long sum=0;
      for(int i:arr)
      sum+=i;
      
       while(N>0) {
           if(sum%N==0) 
           return N;
           
           N--;
       }
      
    }
};