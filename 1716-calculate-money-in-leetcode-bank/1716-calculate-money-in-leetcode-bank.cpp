class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int week=n/7;
        int day=n%7;
        int strt=28;
        for(int i=1;i<=week;i++){
            ans+=strt;
            strt+=7;
        }
        week+=1;
        for(int i=1;i<=day;i++){
            ans+=week;
            week+=1;
        }
        return ans;
    }
};