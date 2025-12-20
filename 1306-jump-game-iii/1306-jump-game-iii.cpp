class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size() || start<0 || arr[start]<0)return false;
        if(start<arr.size() && start>=0 && arr[start]>=0 && arr[start]==0)return true;
        arr[start]=-arr[start];//mark this as visited

        return canReach(arr,start+arr[start])|| canReach(arr,start-arr[start]);

    }
};