class Solution
{
    public:
        int numTeams(vector<int> &rating)
        {
            int n = rating.size();
            int totalCount = 0;
            for (int i = 1; i < n; i++)
            {
                int currSum = 0;
                int less1 = 0, greater1 = 0, less2 = 0, greater2 = 0;
                for (int j = 0; j < i; j++)
                {
                    if (rating[j] < rating[i]) less1++;
                    if (rating[j] > rating[i]) greater1++;
                }
                for (int j = i + 1; j < n; j++)
                {
                    if (rating[j] < rating[i]) less2++;
                    if (rating[j] > rating[i]) greater2++;
                }
                currSum = less1 * greater2;
                int temp = less2 * greater1;
                currSum += temp;
                totalCount += (currSum);
            }
          return   totalCount;
        }
        
};