class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int b = 0;
        int a = 0;
        for (int i = 0; i < n; i++) {
           if(s[i]=='a')a+=1;
           else b+=1;
        }
        int ans = n;
        int leftB = 0;
        for (int i=0; i < n; i++) {
            ans = min(ans, leftB +a);
            leftB += s[i] == 'b';
            a-=s[i]=='a';
            // cout << i << " " << a << " " << leftB << " " << a<< endl;
            ans = min(ans, leftB +a);
        }
        return ans;
    }
};