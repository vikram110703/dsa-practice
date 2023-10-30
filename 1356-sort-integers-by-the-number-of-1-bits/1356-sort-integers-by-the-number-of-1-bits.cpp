class Solution {
public:

    vector<int>sortByBits(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int count_bits=0;
            for(int j=0;j<32;j++){
                if(((arr[i]&(1<<j))>0))count_bits+=1;
            }
            mpp[arr[i]]=count_bits;
        }
    vector<pair<int,int>>v;
      for(int i=0;i<n;i++)v.push_back({arr[i],mpp[arr[i]]});
        
         auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second < b.second;
        };
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<n;i++){
            // cout<<arr[i]<<" "<<mpp[arr[i]]<<endl;
            arr[i]=v[i].first;
        }

        return arr;
    }
    
};