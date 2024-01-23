class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();set<int> s;
        int maxLen = 0;
        
        for(int i = 0;i<=(1<<n)-1;i++){
            int len  = 0;
            s.clear();
            for(int j  =0;j<17;j++){
                if(i & (1<<j)){
                    for(int k = 0;k<arr[j].size();k++){
                        if(s.count(arr[j][k])){
                            len = 0;
                            break;
                        }
                        s.insert(arr[j][k]);
                        len++;
                    }
                }
            }
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};