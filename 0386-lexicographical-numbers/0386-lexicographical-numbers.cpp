class Solution {
public:

    static bool cmp( int &a, int &b){
        string aa=to_string(a);
        string bb=to_string(b);
        // cout<<aa<<" "<<bb<<endl;
        return aa<bb;
    }

    vector<int> lexicalOrder(int n) {
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        sort(v.begin(),v.end(),cmp);
        return v;
    }
};