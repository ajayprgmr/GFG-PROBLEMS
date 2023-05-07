//solution 1 it passes 1110 cases but if you can optimize please give a fork

class Solution {
public:
    string stringMirror(string str) {
        int n = str.size();
        string s1=str;
        reverse(s1.begin(),s1.end());
        string best = str+s1;
        
        for (int i = 0; i < n; i++) {
            string temp = str.substr(0, i+1);
            string rev = temp;
            reverse(rev.begin(), rev.end());
            temp = temp + rev;
            if (temp < best)
                best = temp;
        }

        
        return best;
    }
};


//solution 2 optimal one
class Solution {
public:
    string stringMirror(string str) {
        
        string ans;
        ans.push_back(str[0]);
        for(int i=1;i<str.length();i++){
            if(str[i-1]>str[i] || (i>1 && str[i]==str[i-1]))
            ans.push_back(str[i]);
            else
            break;
        }
        string temp=ans;
        reverse(ans.begin(), ans.end());
        return temp+ans;
      
    }
};