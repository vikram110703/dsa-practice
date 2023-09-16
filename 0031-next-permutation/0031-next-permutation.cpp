class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            multiset<int> st;
            int n = nums.size();
            if (n == 1) return;
            int i = n - 1;
            st.insert(nums[i]);
            i--;
            int a;
            for (i; i >= 0; i--)
            {
                auto it = st.end();
                it--;
                if (*it > nums[i])
                {
                    st.insert(nums[i]);
                    a=nums[i];
                    break;
                }
                else
                {
                    st.insert(nums[i]);
                }
            }
           	// cout<<i<<endl;
            // i=max(i,0);
            if(i==-1){
                sort(nums.begin(),nums.end());return;
            }
            // for (auto it: st) cout << it << " ";
            int firstTime = 1;
            for (i; i < n; i++)
            {
                if (firstTime)
                {
                  auto it=st.begin();
                    for(int j=i;j<n;j++)
                    {
                        if(*it>a){
                            nums[i]=*it;
                            st.erase(it);break;
                        }
                        else it++;
                    }
                    firstTime=0;
                }
                else
                {
                    int a = *st.begin();
                    st.erase(st.begin());
                    nums[i] = a;
                }
            }
        }
};