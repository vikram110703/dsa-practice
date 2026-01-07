class LFUCache {
public:
    int cap;
    int minFreq;

    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end())
            return -1;

        updateFreq(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = value;
            updateFreq(key);
            return;
        }

        if (keyToVal.size() == cap) {
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();

            keyToVal.erase(evictKey);
            keyToFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }

        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }

private:
    void updateFreq(int key) {
        int freq = keyToFreq[key];

        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyToFreq[key]++;
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();
    }
};
