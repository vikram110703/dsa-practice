class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            vector<pair<int, int>> v;
            for (int i = 0; i < 26; i++) v.push_back({ 0,
                i });
            for (int i = 0; i < tasks.size(); i++)
            {
                v[tasks[i] - 'A'].first += 1;
            }
            vector<int> dist(26, -n);
            sort(v.begin(), v.end(),[](pair<int,int>&a,pair<int,int>&b){
                return a.first>b.first;
            } );
            int curr = 0;
            
            // for(int i=0;i<v.size();i++){
            //     cout<<v[i].first<<" "<<v[i].second<<endl;
            // }
         
            while (v[0].first > 0)
            {
                curr += 1;
                // cout<<curr<<" ";
                for (int i = 0; i < 26; i++)
                {
                    // cout<<v[i].first<<" "<<v[i].second<<endl;
                    if (v[i].first > 0 && (curr - dist[v[i].second]) > n)
                    {
                        // cout<<(curr - dist[v[i].second])<<endl;
                        v[i].first -= 1;
                        dist[v[i].second] = curr;
                        // cout<<v[i].second<<endl;
                        break;
                    }
                    else if(v[i].first<=0)break;
                    // else{
                    //     cout<<" -> "<<v[i].second<<"  ";
                    // }
                }
                sort(v.begin(), v.end(),[](pair<int,int>&a,pair<int,int>&b){
                return a.first>b.first;
            } );
            
            }
            
            return curr;
        }
};