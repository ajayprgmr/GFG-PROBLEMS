class Solution {
public:
    bool makePalindrome(int n, vector<string> &arr) {
        unordered_map<string, int> freq; // to store frequency of each string
        
        // count frequency of each string
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        bool hasMiddle = false; // to check if there is a middle string
        string middle; // to store the middle string if it exists
        
        // iterate through each string and check if it is a palindrome
        for (int i = 0; i < n; i++) {
            string rev = arr[i];
            reverse(rev.begin(), rev.end()); // reverse the current string
            
            // if the reversed string is already in the array, skip it
            if (freq[rev] > 0 && arr[i] != rev) {
                freq[arr[i]]--;
                freq[rev]--;
            }
            
            // check if the current string is a palindrome by concatenating it with its reverse
            if (freq[rev] > 0 && arr[i] == rev) {
                freq[arr[i]]--;
                hasMiddle = true;
                middle = arr[i];
            }
        }
        
        // check if it is possible to make a palindromic string
        bool possible = true;
        for (auto f : freq) {
            if (f.second > 0) {
                if (hasMiddle && f.first.size() == middle.size()) {
                    hasMiddle = false;
                } else {
                    possible = false;
                    break;
                }
            }
        }
        
        return possible;
    }
};