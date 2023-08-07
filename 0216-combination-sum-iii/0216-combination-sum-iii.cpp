class Solution {
public:
    void print(int ind,int k,int cnt,int sum,int n,vector<vector<int>>&ans,vector<int>&tmp)
    {
        if(cnt==k||ind>9)
        {  
            if(sum==n)
            {
                ans.push_back(tmp);
            }
            return;
        }
        //take
        if(ind+sum<=n)
        {
            auto it=find(tmp.begin(),tmp.end(),ind);
            if(it==tmp.end())
            {
            tmp.push_back(ind);
            print(ind,k,cnt+1,sum+ind,n,ans,tmp);
            tmp.pop_back();//backTracking
            }
            print(ind+1,k,cnt,sum,n,ans,tmp);
            // tmp.pop_back();
        }
        else
        {
            return;
        }
       
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int cnt=0,sum=0;
        print(1,k,cnt,sum,n,ans,tmp);
        return ans;
        
    }
};