class RandomizedSet {
public:
    unordered_map<int,int>mpp;
    vector<int>v;
    // set<int>st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mpp.count(val)){
            v.push_back(val);
            mpp[val]=v.size()-1 ;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mpp.count(val)){
            auto it=mpp.find(val);
            v[it->second]=v.back();
            mpp[v.back()]=it->second;
            v.pop_back();
            mpp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
       return (v[rand()%v.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */