
class Solution{
public:
    long long findNumber(long long N){
        // Code here
        if(N<=5){
            if(N==1) return 1;
            if(N==2) return 3;
            if(N==3) return 5;
            if(N==4) return 7;
            if(N==5) return 9;
        }
        if(N%5==0)
            return findNumber(N/5-1)*10+9;
            
        
    return findNumber(N/5)*10+ findNumber(N%5);
        
    }
};
