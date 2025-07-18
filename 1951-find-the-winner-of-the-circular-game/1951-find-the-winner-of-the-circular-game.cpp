class Solution {
public:
    int findTheWinner(int n, int k) {

        unordered_map<int,int>mpp;
        int curr=0;

        for(int i=0;i<10000000;i++){
            // cout<<i<<" ";
            if(mpp.size()==n-1){
                cout<<"found ans"<<endl;
                break;
            }
            if(mpp.find(i%n)!=mpp.end())continue;

            curr%=k;
            // cout<<i%n<<" "<<curr<<endl;

            if(curr+1==k){
                mpp[i%n]=1;
            }
            curr+=1;
        }

        for(int i=0;i<n;i++){
            if(mpp.find(i)==mpp.end()){
                return i+1;
            }
        }
        return 1;
    }
};
