class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        
        for (int x : numSet) {
            if (numSet.find(x - 1) == numSet.end()) {
                int y = x + 1;
                while (numSet.find(y) != numSet.end()) {
                    y++;
                }
                best = std::max(best, y - x);
            }
        }
        
        return best;
    }
};

// st.find(x)-> ~~O(1)