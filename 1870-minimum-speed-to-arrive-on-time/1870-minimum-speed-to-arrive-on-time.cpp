class Solution
{
    public:

        double reqTime(vector<int> &dist, int speed)
        {
            double time = 0.0;
            int n = dist.size();
            for (int i = 0; i < dist.size(); i++)
            {
                double a = ((1.0 *dist[i]) / (1.0 *speed));
                if (i != n - 1)
                {
                    if (floor(a) == a)
                    {
                        time += a;
                    }
                    else time += (floor(a)) + 1;
                }
                else time += a;
            }
            return time;
        }
                
    
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int strt = 1, end =INT_MAX, mid, n = dist.size(),minSpeed = INT_MAX;
        while (end - strt > 1)
        {
            mid = strt + (end - strt) / 2;
            double reqdTime = reqTime(dist, mid);

            if (reqdTime <= hour)
            {
                minSpeed = min(minSpeed, mid);
                end = mid;
            }
            else	//reqdTime>hour  
            {
                strt = mid + 1;
            }
        }
        
       	//......final check........................

        // cout << strt << " " << end << " " << minSpeed << endl;
        double ans = 0, ans2 = 0;
        ans = reqTime(dist, strt);
        ans2 = reqTime(dist, end);
        if (ans <= hour) minSpeed = min(minSpeed, strt);
        if (ans2 <= hour) minSpeed = min(minSpeed, end);
       	// cout<<strt<<" "<<end<<endl;
       	// cout<<ans<<" "<<ans2<<endl;
        if (minSpeed != INT_MAX) return minSpeed;
        else
        {
            return -1;
        }
    }
};