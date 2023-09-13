class Solution {
public:
    int hammingWeight(uint32_t n) {
        int out = 0;
        if (n == 0) {
            return 0;
        }
        while(n/2 != 0) {
            out += n%2;
            n /= 2;
        }
        out+=1;
        return out;
    }
};