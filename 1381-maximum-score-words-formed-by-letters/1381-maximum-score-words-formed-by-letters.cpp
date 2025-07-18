class Solution {
public:

    int calculate(int ind,vector<int>&freq,vector<string>&words,vector<char>&letters,vector<int>&score)
    {
        //base condition
        if(ind>=words.size()){
            return 0;
        }

        int take=0,notTake=0;

        // not  take
        notTake=0+calculate(ind+1,freq,words,letters,score);

        //take
        bool flag=true;
        int tmp=0;
        for(int i=0;i<words[ind].size();i++)
        {
            freq[words[ind][i]-'a']--;
            if((freq[words[ind][i]-'a'])<0)flag=false;
            tmp+=score[words[ind][i]-'a'];
            cout<<tmp<<endl;
        }

        // word can be formed
        if(flag==true){
            take=tmp+calculate(ind+1,freq,words,letters,score);
        }
        
        //undo changes
        for(int i=0;i<words[ind].size();i++)
        {
            freq[words[ind][i]-'a']++;
        }

        return max(take,notTake);

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        return calculate(0,freq,words,letters,score);   
    }
};