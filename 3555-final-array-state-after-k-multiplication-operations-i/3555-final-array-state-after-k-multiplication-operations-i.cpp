#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<int, int>> st;
        
        for (int i = 0; i < nums.size(); ++i) {
            st.insert({nums[i], i});
        }

        while (k--) {
            // Get the smallest element
            auto it = st.begin();
            int val = it->first;
            int ind = it->second;
            st.erase(it);

            // Update the element with multiplied value
            int newValue = val * multiplier;
            st.insert({newValue, ind});
        }

        // Rebuild the final state of the nums array
        for (const auto& p : st) {
            nums[p.second] = p.first;
        }

        return nums;
    }
};
