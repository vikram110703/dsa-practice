class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt=0;
        sort(events.begin(),events.end());
        int d=events[0][0];
        int i=0,n=events.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        //we will insert the endDay of event
        while(i<n||pq.size()>0){
            if(pq.size()==0){
                d=events[i][0];
            }
            while(i<n&&events[i][0]==d){
                pq.push(events[i][1]);
                i+=1;
            }
            cnt+=1;d+=1;
            pq.pop();
             //remove events whose endDay<currentDay
            while(pq.size()>0&&pq.top()<d){
                pq.pop();
            }
            
            
        }
        
        
        
        return cnt;
    }
};