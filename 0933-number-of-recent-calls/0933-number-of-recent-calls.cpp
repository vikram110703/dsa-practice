class RecentCounter {
public:
    queue<int>q;
    RecentCounter(){};
    
    int ping(int t) {
        q.push(t);
        int cnt=0,minReq=t-3000;
        while(!q.empty()){
            if(q.front()<minReq)q.pop();
            else break;
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */