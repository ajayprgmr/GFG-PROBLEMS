class Solution {
public:
    int bitMagic(int n, vector<int> &arr) {
        int count = 0;
        for (int i = 0; i < n/2; i++) {
            if (arr[i] != arr[n-1-i]) {
                int result = arr[i] ^ arr[n-1-i];
                arr[i] ^= result;
                arr[n-1-i] ^= result;
                count++;
            }
        }
        return count;
    }
};
