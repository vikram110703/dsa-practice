class Solution {
public:

    void calculate(int start,int n,int k,vector<int>&v){
        //base condition 
        if(v.size()==1){
            return;
        }
        //index to be removed
        int ind=(start+k-1)%n;
        // cout<<start<<" "<<ind<<endl;
        v.erase(v.begin()+ind);
        start=(ind%n);

        calculate(start,v.size(),k,v);
    }

    int findTheWinner(int n, int k) {
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }

        calculate(0,n,k,v);
        return v[0];
    }
};
