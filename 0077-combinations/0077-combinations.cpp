class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,int n,int k,vector<int>&curr){
        if(ind>n || curr.size()>=k){
            if(curr.size()==k)ans.push_back(curr);
            return;
        }
        //take
        curr.push_back(ind);
        solve(ind+1,n,k,curr);

        // backtrack
        curr.pop_back();
        solve(ind+1,n,k,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        solve(1,n,k,curr);
        return ans;
    }
};