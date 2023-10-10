class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<int>st;//handle duplicated
        unordered_map<int,int>mpp;
        vector<int>dup(n,0);
        for(int i=0;i<n;i++)
        {
            // cout<<nums[i]<<" ";
            st.insert(nums[i]);
            if(i==0){
                dup[i]=0;mpp[nums[i]]++;
            }
            else{
                if(mpp[nums[i]]>0){
                    dup[i]=dup[i-1]+1;
                }
                else{
                    dup[i]=dup[i-1];
                    mpp[nums[i]]++;
                }
            }
        }
        // cout<<endl;
        
        int mini=n;
        for(auto &elem:st){
            //range[nums[i],nums[i]+n-1] ,  need to remove elements outside  this  range 
            int last=elem+n-1;
            auto k= (lower_bound(nums.begin(),nums.end(),elem)-nums.begin());
            int less=k;
            auto it=upper_bound(nums.begin(),nums.end(),last)-nums.begin();    
            int greater=n-it;
            
            // cout<<less<<" "<<greater<<endl;
            
            // duplicates in range  [ ]
            int duplicates=0;
            if(it==n)duplicates=dup[n-1];
            else duplicates=dup[it];
            //remove before range[ ]
            duplicates-=dup[k];
            // cout<<duplicates<<endl;
            int req_remove=less+greater+duplicates;
            mini=min(mini,req_remove);
            
        }
        return mini;
        
    }
};