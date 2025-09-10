class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        char startInd = '1';
        int curr_int = low;
        int len = (to_string(low)).size();
        while (len <= 9) {
            char start='1';
            while (start <= '9') {
                string tmp = "";
                bool failed = false;
                for (char i = start; tmp.size() < len; i++) {
                    tmp += i;
                    if (i == '9' && tmp.size() < len)
                        break;
                }
                if (tmp.size() == len) {
                    int curr = stoi(tmp);
                    if (curr >= low && curr <= high)
                        ans.push_back(curr);
                }
                if(start=='9')break;
                start++;
            }
            len++;
        }
        return ans;
    }
};