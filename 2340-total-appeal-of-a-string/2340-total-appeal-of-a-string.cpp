class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        vector<int>lastInd(26,0);
        int n=s.size();
        long long sum=0;
        vector<long long>res(n,0);
        for(int i=n-1;i>=0;i--){
            long long aa=n-i;//1based index from end
            sum+=aa;//kind of suffix sum of index
            long long bb=lastInd[s[i]-'a'];
            sum-=bb;//if repeating then remove next occ ind
            lastInd[s[i]-'a']=aa;// update index of occurence
            res[i]=sum;
        }
        for(auto &it:res){
            ans+=it;
        }
        return ans;
    }
};

// a,ab,abb,abbc,abbca = 11
// b,bb,bbc,bbca = 7
// b,bc,bca = 6
// c,ca = 3
// a = 1

// a=5
// b=4
// b=3
// c=2,
// a=1


// 11,7,6,3,1


