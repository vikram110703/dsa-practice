class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char>chars={s.begin(),s.end()};
        int maxScore=0;
        for(auto &a:chars){
            for(auto &b:chars){
                int currScore=0;
                bool substring_has_b=false;
                bool substring_startsWith_b=false;

                for(int i=0;i<s.size();i++){
                    if(s[i]!=a && s[i]!=b)continue;

                    if(s[i]==a)currScore+=1;
                    else{
                        substring_has_b=true;
                        if(substring_startsWith_b &&currScore>=0){
                            substring_startsWith_b=false;
                            //abhi jo starting wala b th use substring se hata de rahe hai
                            //to uski vajah se -1 kiye the score me usko componset karne ke liye 
                            // ye wale b ka score -1 nhi kaar rhe hai
                        }
                        else if(currScore<=0){
                            substring_startsWith_b=true;
                            currScore=-1;
                        }
                        else currScore-=1;
                    }
                    if(substring_has_b==true){
                        maxScore=max(maxScore,currScore);
                    }
                }
            }
        }

        return maxScore;
    }
};