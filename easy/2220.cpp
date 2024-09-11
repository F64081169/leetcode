class Solution {
public:
    int minBitFlips(int start, int goal) {
        // xor and count ones
        return __builtin_popcount(start^goal);

    }
};
