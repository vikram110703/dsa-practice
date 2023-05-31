class UndergroundSystem {
public:
    unordered_map<int,pair<int,string>>In;
    unordered_map<string,pair<int,int>>Out;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        In[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start=In[id].second;
        string route=start+'_'+stationName;
        int time=t-In[id].first;
        Out[route].second+=1;
        Out[route].first+=time;
        In.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+'_'+endStation;
        double avg=0;
        if(Out.find(route)!=Out.end())
        avg=(Out[route].first*1.0)/(Out[route].second*1.0);
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */