class Solution {
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       map<int,int>mpp;
        for(int i=0;i<mapping.size();i++){
            mpp[i]=mapping[i];
        }
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            string tmp=to_string(nums[i]);
            // cout<<tmp<<" ";
            for(int j=0;j<tmp.size();j++){
                tmp[j]=mpp[tmp[j]-'0']+'0';
            }
            int j=0;
            while(j<tmp.size()&&tmp[j]=='0')j+=1;
            if(j-1>0)
            tmp.erase(0,j-1);
            // cout<<tmp<<" "<<nums[i]<<endl;
            v.push_back({stoi(tmp),nums[i]});
            // cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        sort(v.begin(),v.end(),[](const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) {
        // return a.first > b.first;
        return false;
    }
     else {
        return a.first < b.first;
    }
});
        for(int i=0;i<v.size();i++){
            nums[i]=v[i].second;
        }
        return nums;
    }
};