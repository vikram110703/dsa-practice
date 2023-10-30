class Solution {
public:
      static bool cmp (int a, int b) {
            if(count_bits(a)==count_bits(b))return a<b;
             else return count_bits(a)<count_bits(b);
        };
    
     static int count_bits(int &num){
        int count=0;
        for(int i=0;i<32;i++){
            if(((1<<i)&num)>0)count+=1;
        }
        return count;
    }
    
    vector<int>sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
    
};