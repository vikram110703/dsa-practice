class Solution
{
    public:
        int singleNonDuplicate(vector<int> &v)
        {

            int strt = 0, end = v.size() - 1, mid, n = v.size();
            int ans = -1;
            while (strt < end)
            {
                mid = strt + (end - strt) / 2;

                if (mid % 2 == 0)
                {

                    if ((mid + 1 < n) && v[mid] == v[mid + 1])
                    {
                        strt = mid + 1;
                    }
                    else if ((mid - 1 >= 0) && ((mid + 1 < n) && v[mid] == v[mid - 1]))
                        {
                            end = mid - 1;
                        }
                        else return v[mid];
                    }
                    else
                    {
                        if ((mid - 1 >= 0) && v[mid] == v[mid - 1])
                        {
                            strt = mid + 1;
                        }
                        else if ((mid + 1 < n) && v[mid] == v[mid + 1])
                        {
                            end = mid - 1;
                        }
                        else return v[mid];
                    }
                }
                return v[strt];
            }
        };