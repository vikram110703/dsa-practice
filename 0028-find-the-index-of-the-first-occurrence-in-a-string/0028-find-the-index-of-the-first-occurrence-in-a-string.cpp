class Solution {
public:
    int strStr(string haystack, string needle) {
        string tmp="";
        int n=haystack.size();
        int i=0;
        int start=0;
        while(i<n && i<needle.size()){
            tmp+=haystack[i];
            i+=1;
        }
        if(tmp==needle)return start;
        while(i<n){
            tmp.erase(0,1);
            tmp+=haystack[i++];
            start++;
            if(tmp==needle)return start;
        }
        return -1;
    }
};