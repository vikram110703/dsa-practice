class Solution {
public:
    string getHint(string secret, string guess) {
        int m=guess.size();
        unordered_map<char,int>freq;
        int cow=0,bull=0;
        // sort(secret.begin(),secret.end());
        // sort(guess.begin(),guess.end());
        // if(guess==secret)cout<<"YES";
        
        for(int i=0;i<m;i++){
            if(secret[i]==guess[i])bull+=1;
            else
            freq[guess[i]]++;
        }
        
        for(int i=0;i<m;i++){
            if(secret[i]!=guess[i]){
                if(freq[secret[i]]>0){
                    cow+=1;
                    freq[secret[i]]-=1;
                }
            }
            
        }
        
        string a=to_string(bull);
        string b=to_string(cow);
        // cout<<m<<endl;
        
        return a+"A"+b+"B";
    }
};