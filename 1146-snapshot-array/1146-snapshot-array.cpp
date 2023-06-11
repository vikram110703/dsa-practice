#include <vector>
#include <map>
#include <set>
using namespace std;

class SnapshotArray {
public:
    int cnt = 0;
    vector<vector<pair<int, int>>> arr;

    SnapshotArray(int length) {
        arr.resize(length, {{0, 0}});
    }

    void set(int index, int val) {
        arr[index].push_back({cnt, val});
    }

    int snap() {
        int tmp = cnt;
        cnt += 1;
        return tmp;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        if (it != arr[index].begin())
        {
            it--;
            return it->second;
        }
        return 0;
    }
};
