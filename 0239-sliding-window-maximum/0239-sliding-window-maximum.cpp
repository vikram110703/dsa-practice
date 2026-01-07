class Solution {
public:
//time o(nlog(n))
//space o(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // (value, index)
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            // window starts forming when i >= k - 1
            if (i >= k - 1) {
                // remove elements outside window
                while (!pq.empty() && pq.top().second <= i - k) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};

// deque SOLUTION 
// time O(n) space o(k) , maintain a decreasing order deque ... [fronnt -----back]
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;  // stores indices
//         vector<int> ans;

//         for (int i = 0; i < nums.size(); i++) {

//             // 1. Remove indices out of window
//             if (!dq.empty() && dq.front() <= i - k) {
//                 dq.pop_front();
//             }

//             // 2. Maintain decreasing order in deque
//             while (!dq.empty() && nums[dq.back()] <= nums[i]) {
//                 dq.pop_back();
//             }

//             // 3. Add current index
//             dq.push_back(i);

//             // 4. Record answer once window is valid
//             if (i >= k - 1) {
//                 ans.push_back(nums[dq.front()]);
//             }
//         }
//         return ans;
//     }
