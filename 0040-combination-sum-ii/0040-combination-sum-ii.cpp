class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        solve(v,0,target);
        return ans;
    }

    void solve(vector<int>&v,int strt,int target){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(target<1 || strt>v.size())return;

        for(int i=strt;i<v.size();i++){
            if(i>strt && v[i]==v[i-1])continue; //skip duplicates
            
            tmp.push_back(v[i]);
            solve(v,i+1,target-v[i]);

            tmp.pop_back();//without  arr[i] element
        }
    }

};
