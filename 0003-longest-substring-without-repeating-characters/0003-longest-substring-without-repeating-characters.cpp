class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>freq;
        int maxi=0,currMax=0;
        int i=0,j=0;
        while(i<=j && j<n){
            if(freq[s[j]]==0){
                freq[s[j]]++;
                j+=1;
                maxi=max(maxi,j-i);
            }
            else{
                // this curr char is already present
                maxi=max(maxi,j-i);
                while(i<j && freq[s[j]]>0){
                    freq[s[i]]--;
                    i++;
                }
                freq[s[j]]++;
                j++;
            }
        }
        return maxi;
    }
};