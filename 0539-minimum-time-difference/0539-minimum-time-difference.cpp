class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int mini = 24 * 60; // minutes
        vector<int>minutes;

        int ind=1;
        for (auto& it : timePoints) {
            int h = stoi(it.substr(0, 2)); // hours
            int m = stoi(it.substr(3, 3)); // minutes

            int curr_minutes = (h * 60) + m;
            minutes.push_back(curr_minutes);
        }

        sort(minutes.begin(),minutes.end());

        for (int i = 1; i < minutes.size(); i++) {
            int curr_diff=minutes[i]-minutes[i-1];
            mini=min(mini,curr_diff);
        }

        // last element - first element : in circular manner 
        int circular_diff=((24*60)-minutes.back())+minutes.front();
        mini=min(mini,circular_diff);

        return mini;
    }
};