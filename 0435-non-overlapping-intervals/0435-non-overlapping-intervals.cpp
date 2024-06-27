class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>temp;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            if(temp.size()>0){
                int ll=temp.back().first;
                int rr=temp.back().second;
                //overlaping interval to the last interval in our data structure
                if(rr>l){
                   if(rr>r){
                       temp.back()={l,r};
                   }
                    else{
                        ;//
                    }
                }
                else temp.push_back({l,r});
            }
            else{
                temp.push_back({l,r});
            }
        }
        
        return n-temp.size();
    }
};