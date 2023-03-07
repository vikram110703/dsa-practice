
#define ll long long
class Solution
{
    public:
        long long minimumTime(vector<int> &time, int k)
        {

            sort(time.begin(), time.end());
            int n = time.size();
            ll strt = (time[0]*1ll), end = ((k*1ll) *(time[0]*1ll));
            ll mid, trips = 0;
            while (end - strt > 1)
            {
                trips=0;
                mid = strt + (end - strt) / 2;
                // cout << " mid " << mid << " strt " << strt << " end " << end;
                for (int i = 0; i < n; i++)
                {
                    trips += ((mid / (time[i]*(1ll))));
                }
        
                if (trips < k)
                {
                    strt = mid + 1;
                }
                else if (trips >= k)
                {
                    end = mid;
                }
            }
            trips=0;
            for (int i = 0; i < n; i++)
            {
                trips += ((strt / (time[i]*1ll)));
            }
            if(trips>=k)return  strt;
            else return end;
            
        }
};