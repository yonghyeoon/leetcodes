// Source: https://leetcode.com/problems/most-profit-assigning-work/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        for (int work : worker) {
            int max_idx = -1;
            int max_profit = -1;
            for (int curr = 0; curr < difficulty.size(); curr++) {
                if (work >= difficulty[curr] && profit[curr] > max_profit) {
                    max_idx = curr;
                    max_profit = profit[curr];
                }
            }

            if (max_idx > -1 && max_profit > -1) {
                ans += max_profit;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> difficulty = { 2, 4, 6, 8, 10 };
    vector<int> profit = { 10, 20, 30, 40, 50 };
    vector<int> worker = { 4, 5, 6, 7 };

    cout << solution.maxProfitAssignment(difficulty, profit, worker) << endl;

    return 0;
}