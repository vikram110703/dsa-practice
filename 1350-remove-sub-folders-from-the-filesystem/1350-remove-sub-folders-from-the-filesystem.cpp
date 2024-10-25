class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
        map<string,int>mpp;
        for(int i=0;i<n;i++)
        {
            string s="/";
            bool take=true;
            int m=folder[i].size();
            for(int j=1;j<m;j++)
            {
                while(j<m && folder[i][j]!='/')
                {
                    s+=folder[i][j];j++;
                }

                if(mpp.find(s)!=mpp.end()){
                    take=false;
                    break;
                }
               if(j<m)s+=folder[i][j];
            }
            if(take)mpp[s]+=1;
        }
        folder.resize(mpp.size());
        int i=0;
        for(auto &it:mpp){
            folder[i++]=it.first;
        }

        return folder;
    }
};