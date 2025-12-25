class Solution {
public:
    void countBits(int a, vector<int>& bits) {
        for (int i = 0; i < 32; i++) {
            if (a & (1 << i)) bits[i]++;
        }
    }

    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);

        for (int num : nums) {
            countBits(num, bits);
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
