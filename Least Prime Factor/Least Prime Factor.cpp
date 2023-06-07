// problem link : https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1

// Bruteforce solution  O(n2)
#include <bitset>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        bitset<32> bitsA(a);
        bitset<32> bitsB(b);
        bitset<32> bitsC(c);

        for (int i = 0; i < 32; i++) {
            bool bitA = bitsA[i];
            bool bitB = bitsB[i];
            bool bitC = bitsC[i];

            if (bitC == 0) {
                if (bitA == 1 && bitB == 1) {
                    flips += 2;
                } else if (bitA == 1 || bitB == 1) {
                    flips += 1;
                }
            } else {
                if (bitA == 0 && bitB == 0) {
                    flips += 1;
                }
            }
        }

        return flips;
    }
};

