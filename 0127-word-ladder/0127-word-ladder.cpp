class Solution {
public:
// I treat each word as a node and use BFS to find the shortest path 
// where edges represent one-letter transformations
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int j = 0; j < word.length(); j++) {
                    char original = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        word[j] = c;

                        if (dict.find(word) != dict.end() &&
                            visited.find(word) == visited.end()) {

                            visited.insert(word);
                            q.push(word);
                        }
                    }

                    word[j] = original;
                }
            }
            level++;
        }

        return 0;
    }
};
