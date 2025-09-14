class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>pq;//max Heap 
        for(auto &it:points){
            double dist=sqrt((it[0]*it[0])+(it[1]*it[1]));
            pq.push({-1.0*dist,it});//min heap
        }
        vector<vector<int>>ans;
        while(!pq.empty()&&k>0){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};