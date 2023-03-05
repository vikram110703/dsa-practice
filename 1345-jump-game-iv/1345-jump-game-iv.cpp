class Solution
{
    public:

        int minJumps(vector<int> &arr)
        {
            int n = arr.size();
            unordered_map<int, vector < int>> mpp;
            for (int i = 0; i < n; i++)
            {

                mpp[arr[i]].push_back(i);
            }
            queue<int> q;
           	//visited map
            unordered_map<int, bool> viss;
            q.push(0);
            viss[0] = true;

           	//bfs for every element present in mpp;
            int ans = 0;
            while (!q.empty())
            {
                int size = q.size();
                while (size > 0)
                {
                    int ff = q.front();
                    q.pop();
                   	// last ind
                    if (ff == n - 1) return ans;
                    vector<int> &tmp = mpp[arr[ff]];
                    if (ff - 1 >= 0) tmp.push_back(ff - 1);
                    if (ff + 1 < n) tmp.push_back(ff + 1);

                    for (auto &it: tmp)
                    {
                        if (viss[it] == false)
                        {
                            viss[it] = true;
                            q.push(it);
                        }
                    }

                   	// clear to reduce memory use of we traverse through this ind;
                    tmp.clear();
                    size-=1;
                }
               	// steps++;
                ans += 1;
            }
             return ans;
        }
   
};