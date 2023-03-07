class Solution
{
    public:
        int findDuplicate(vector<int> &v)
        {
            int n = v.size();
            int index = 1;
            for (int i = 0; i < n; i++)
            {
               	//index 
                
               
                index=abs(v[i])-1;
                if (v[index] < 0)
                {
                    return index + 1;
                }
                else
                {
                    v[index] *= -1;
                }
            }
            return index;
        }
};