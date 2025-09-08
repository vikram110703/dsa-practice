class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = end(s);    
    void add(string name, int score) {
        auto it1 = s.insert({-score, name}).first;

        if (it == s.end() || *it1 < *it)// check notes
            --it;
    }
    string get() {
        return (it++)->second;
    }
};