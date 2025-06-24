class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        
        // Store all indices where nums[i] == key
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                st.insert(i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // Use lower_bound or custom iterator logic to find nearest key index
            // Check left and right neighbors within distance k

            // check left
            auto it = st.upper_bound(i);
            if (it != st.begin()) {
                --it;
                if (i - *it <= k) {
                    ans.push_back(i);
                    continue; // no need to check right if already valid
                }
                ++it; // restore iterator for right check
            }

            // check right
            if (it != st.end() && *it - i <= k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
