class Solution {
public:
    void calculate(string curr, int n, vector<int>& v) {
        for (char j = 0; j <= 9; j++) {
            if (curr.size() == 0 && j == 0)
                continue;

            string tmp = curr + to_string(j);
            if (tmp.size() > 0 && stoi(tmp) > n)
                return;
            v.push_back(stoi(tmp));
            calculate(tmp, n, v);
        }
        
    }

    vector<int> lexicalOrder(int n) {

        string curr = "";
        vector<int> v;
        calculate(curr, n, v);
        return v;
    }
};