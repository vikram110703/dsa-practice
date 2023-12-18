class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int strt=1,end=INT_MAX,mid;
        while(end-strt>1){
            mid=strt+(end-strt)/2;
            int timeTaken=0;
            for(int i=0;i<n;i++){
                timeTaken+=(piles[i]/mid);
                if(piles[i]%mid>0)timeTaken+=1;
            }
            if(timeTaken>h)strt=mid+1;
            else end=mid;
        }
      int timeTaken=0;
            for(int i=0;i<n;i++){
                timeTaken+=(piles[i]/strt);
                if(piles[i]%strt>0)timeTaken+=1;
            }
        if(timeTaken<=h)return strt;
        return end;
    }
};