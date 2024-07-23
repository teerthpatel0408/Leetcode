#include <vector>
#include <unordered_map>
using namespace std;

class SnapshotArray {
private:
    unordered_map<int, vector<pair<int, int>>> history;
    int snapCount = 0;

public:
    SnapshotArray(int length) {
    }

    void set(int index, int val) {
        if (!history[index].empty() && history[index].back().first == snapCount) {
            history[index].back().second = val;
        } else {
            history[index].push_back({snapCount, val});
        }
    }

    int snap() {
        return snapCount++;
    }

    int get(int index, int snap_id) {
        const auto& changes = history[index];
        int l = 0, r = changes.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (changes[mid].first <= snap_id) {
                if (mid == changes.size() - 1 || changes[mid + 1].first > snap_id) {
                    return changes[mid].second;
                }
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return 0; 
    }
};