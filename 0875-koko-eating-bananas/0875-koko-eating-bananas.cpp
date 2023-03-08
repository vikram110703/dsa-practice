class Solution
{
    public:
        int minEatingSpeed(vector<int> &v, int h)
        {
            sort(v.begin(), v.end());
            int n = v.size();
            int strt = 1, end, mid;
            if (h >= n)
                end = *max_element(v.begin(), v.end());
            else
            {
                end = *max_element(v.begin(), v.end()) *h;
            }
            // cout<<" strt "<<strt<<" end "<<end<<endl;
            int reqTime = 0;
            while (end - strt > 1)
            {
                mid = strt + (end - strt) / 2;
                // cout<<" mid "<<mid<<" ";
                reqTime = 0;
                for (int i = 0; i < n; i++)
                {
                    if (v[i] % mid == 0)
                    {
                        reqTime += v[i] / mid;
                    }
                    else
                    {
                        reqTime += (v[i] / mid) + 1;
                    }
                }
                if (reqTime > h)
                {
                    strt = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
            reqTime = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] % strt == 0)
                {
                    reqTime += v[i] / strt;
                }
                else
                {
                    reqTime += (v[i] / strt) + 1;
                }
            }
            if (reqTime <= h)
                return strt;
            else
                return end;
        }
};