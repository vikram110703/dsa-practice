class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b){
        return ((a[0]*a[0])+(a[1]*a[1]))<((b[0]*b[0])+(b[1]*b[1]));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sol 1 :
        vector<vector<int>>ans;
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(points[i]);
        }
        return ans;

        // sol 2: 

        // priority_queue<pair<double,vector<int>>>pq;//max Heap 
        // for(auto &it:points){
        //     double dist=(it[0]*it[0])+(it[1]*it[1]);
        //     pq.push({-1.0*dist,it});//min heap
        // }
        // vector<vector<int>>ans;
        // while(!pq.empty()&&k>0){
        //     auto it=pq.top();
        //     pq.pop();
        //     ans.push_back(it.second);
        //     k--;
        // }
        // return ans;
    }
};