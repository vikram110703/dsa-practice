class Solution {
public:
    // "**|**|***|"
    // for range [1,9] output is 5

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>left(n+1,-1),right(n+1,-1),pref(n+1,0);
        int ind=-1,candles=0;
        for(int i=0;i<n;i++){
            candles+=s[i]=='|';
            pref[i+1]=candles;//prefix sum of candles
            if(s[i]=='|'){
                ind=i;
            }
            left[i]=ind;
        }
        ind=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|'){
                ind=i;
            }
            right[i]=ind;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int leftRange=queries[i][0];
            int rightRange=queries[i][1];
            int l=right[leftRange];
            int r=left[rightRange];
            // cout<<n<<" "<<l<<" "<<r<<endl;
            if(l==-1||r==-1)ans.push_back(0);
            else if(l<leftRange||l>rightRange||r>rightRange||r<leftRange)ans.push_back(0);
            else{
                ans.push_back((r-l+1)-(pref[rightRange+1]-pref[leftRange]));
            }
        }
        return ans;
    }
};