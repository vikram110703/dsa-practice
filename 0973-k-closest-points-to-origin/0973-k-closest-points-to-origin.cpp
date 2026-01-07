class Solution {
public:
    int dist(vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap: (distance, point)
        priority_queue<pair<int, vector<int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            int d = dist(points[i]);

            if (pq.size() < k) {
                pq.push({d, points[i]});
            } else if (d < pq.top().first) {
                pq.pop();
                pq.push({d, points[i]});
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
