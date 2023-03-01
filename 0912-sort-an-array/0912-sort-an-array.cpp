class Solution
{
    void msort(vector<int> &v, int strt, int end)
    {
        if (strt >= end)
            return;
        int mid = strt + (end - strt) / 2;

        msort(v, strt, mid);
        msort(v, mid + 1, end);

        int i = strt, j = mid + 1;
        vector<int> tmp;

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
    }

public:
    vector<int> sortArray(vector<int> &v)
    {
        int strt = 0, end = v.size() - 1;
        msort(v, strt, end);
        return v;
    }
};