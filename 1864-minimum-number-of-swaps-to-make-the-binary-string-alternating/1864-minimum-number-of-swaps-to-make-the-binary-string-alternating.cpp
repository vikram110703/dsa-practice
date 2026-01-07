class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int one = 0, zero = 0;

        for (char c : s) {
            if (c == '1') one++;
            else zero++;
        }

        if (abs(one - zero) > 1) return -1;

        int mismatch0 = 0; // expected pattern: 0101...
        int mismatch1 = 0; // expected pattern: 1010...

        for (int i = 0; i < n; i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0) mismatch0++;
            if (s[i] != expected1) mismatch1++;
        }

        // Only valid patterns depending on counts
        if (one > zero) {
            return mismatch1 / 2; // must start with '1'
        }
        if (zero > one) {
            return mismatch0 / 2; // must start with '0'
        }

        // both patterns valid
        return min(mismatch0, mismatch1) / 2;
    }
};
