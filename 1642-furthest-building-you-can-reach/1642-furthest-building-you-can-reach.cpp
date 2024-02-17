class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n=h.size();
        priority_queue<int>pq;
        for(int i=0;i<n-1;i++){
            int diff=h[i+1]-h[i];
            pq.push(diff);
            if(diff>0){
                bricks-=diff;
                if(bricks<0){
                    while(pq.size()>0&&bricks<0){
                        bricks+=pq.top();
                        pq.pop();
                        ladders-=1;
                    }
                    if(ladders<0)return i;
                }
            }
        }
        return n-1;
    }
};