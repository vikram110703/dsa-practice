class Solution {
public:
  
    
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans="1";
        for(int i=2;i<=n;i++){
            // cout<<ans<<" ";
            string tmp="";
            int nn=ans.size();
            if(nn==1){
                ans="11";
            }
            else{
                int cnt=0;
                for(int ii=1;ii<nn;ii++){
                    if(ans[ii]==ans[ii-1]){
                        cnt+=1;
                    }
                    else{
                        cnt+=1;
                        string aa=to_string(cnt);
                        tmp+=aa;
                        tmp+=ans[ii-1];
                        cnt=0;
                    }
                }
                // if(ii==nn){
                    // cout<<"aa hua";
                        cnt+=1;
                        string aa=to_string(cnt);
                        tmp+=aa;
                        tmp+=ans[nn-1];
                      ans=tmp;
                // }
                       
            }
            
        }
        return ans;
    }
};