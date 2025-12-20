class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int surplus = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }
};
// For those who are still confused why we are not checking again at all indices (in optimized approach).
// Firstly we can start at index i, only when gas[i] - cost[i]>=0 because otherwise, we won't be able to reach the next station.
// Also, we will try to have the maximum value of gas in our tank at a given index because having greater fuel maximizes chances of getting success(here success means completing one circular trip) for future.
// So if we try to start at index i where gas[i]-cost[i]>=0 and we get to know that we are not able to reach at index j (starting from i) , so it is not beneficial to check at indices (i+1,i+2,...,j-1) because if we start at indices (i+1,i+2,...j-1) it will result in less amount of gas in our car at station j which will definitely be a failure.