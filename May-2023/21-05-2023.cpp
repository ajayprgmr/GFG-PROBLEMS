// c++ solution
class Solution {
  public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) {
        
        //chairs -->n
        // passengers -->n
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        int sum=0;
         for(int i=0; i<n; i++) {
             sum=sum+abs(passengers[i]-chairs[i]);
         }
        return sum;
    }
};