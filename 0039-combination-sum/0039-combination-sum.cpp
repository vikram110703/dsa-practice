class Solution {
public:
    void solve(int ind,int sum,vector<int>&tmp,vector<int>&v,vector<vector<int>>&ans)
    {
        
        if(ind>=v.size())
        {
            if(sum==0){
                auto it=find(ans.begin(),ans.end(),tmp);
                if(it==ans.end())
                ans.push_back(tmp);
            }
            return;
        }
        
        if(v[ind]<=sum){
            //take 
            tmp.push_back(v[ind]);
            solve(ind+1,sum-v[ind],tmp,v,ans);
            // take but no move
            tmp.pop_back();
            tmp.push_back(v[ind]);
            solve(ind,sum-v[ind],tmp,v,ans);
            //not take
            tmp.pop_back();
            solve(ind+1,sum,tmp,v,ans);
        }
        else{
            //not Take
            solve(ind+1,sum,tmp,v,ans);
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<int>tmp;
        vector<vector<int>>ans;
        solve(0,target,tmp,v,ans);
        return ans;
        
    }
};