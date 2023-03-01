class Solution
{
    void msort(vector<int> &v, int strt, int end, vector<int> &tmp)
    {
        if (strt >= end)
            return;
        int mid = strt + (end - strt) / 2;

        msort(v, strt, mid,tmp);
        msort(v, mid + 1, end,tmp);

        int i = strt, j = mid + 1;
       

        while (i <= mid && j <= end)
        {
            if (v[i] <= v[j])
            {
                tmp.push_back(v[i]);
                i += 1;
            }
            else
            {
                tmp.push_back(v[j]);
                j += 1;
            }
        }

        while (i <= mid)
        {
            tmp.push_back(v[i]);
            i += 1;
        }

        while (j <= end)
        {
            tmp.push_back(v[j]);
            j += 1;
        }

        for (int k = strt; k <= end; k++)
        {
            v[k] = tmp[k - strt];
        }
        tmp.clear();
            
    }

public:
    vector<int> sortArray(vector<int> &v)
    {
        int strt = 0, end = v.size() - 1;
        vector<int>tmp;
        msort(v, strt, end,tmp);
        return v;
    }
};