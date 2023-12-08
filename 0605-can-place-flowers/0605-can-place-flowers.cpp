class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
      if(m==1){
          if(flowerbed[0]==0&&n<=1)return true;
          else if(flowerbed[0]==1&&n==0)return true;
          else return false;
      }
            if(flowerbed[0]==0&&flowerbed[1]==0){
                n-=1;
                flowerbed[0]=1;
            }
        
        for(int i=1;i<m-1;i++){
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){
                n-=1;
                flowerbed[i]=1;
            }
        }
        if(flowerbed[m-1]==0&&flowerbed[m-2]==0)n-=1;
        // cout<<n<<endl;
        if(n<=0)return true;
        else return false;
       
    }
};