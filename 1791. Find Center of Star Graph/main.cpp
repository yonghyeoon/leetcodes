#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;

        for (auto edge : edges) {
            //cout << edge[0] << edge[1] << endl;
            mp[edge[0]]++;
            mp[edge[1]]++;
        }

        int max_idx = -1, max_cnt = 0;
        for (auto it : mp) {
            if (it.second > max_cnt) {
                max_cnt = it.second;
                max_idx = it.first;
            }
        }
        return max_idx;
    }
};

int main(void) {
    Solution sol;
    vector<vector<int>> edges = { {1,2},{2,3},{4,2} };
    cout << sol.findCenter(edges) << endl;
    return 0;
}