class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
  
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
            
        }
       
        while(pq.size()>1)
        {
            int a=pq.top();pq.pop();
            if(!pq.empty())
            {
                int b=pq.top();
                pq.pop();
                if(a!=b)
                {
                    pq.push(a-b);
                }
            }
        }
        if(!pq.empty())return pq.top();
        else return 0;
        
    }
};