/*
* Problem URL : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
* Example 1:
* Input: prices = [8,4,6,2,3]
* Output: [4,2,4,2,3]
* 
* Example 2:
* Input: prices = [1,2,3,4,5]
* Output: [1,2,3,4,5]
* 
* Example 3:
* Input: prices = [10,1,1,6]
* Output: [9,0,1,6] 
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer = prices;

        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[i] >= prices[j]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    // Example 1
    vector<int> prices = { 8,4,6,2,3 };

    // Example 2
    // vector<int> prices = { 1,2,3,4,5 };

    // Example 3
    // vector<int> prices = { 10,1,1,6 };

    Solution solution = Solution();
    vector<int> ret = solution.finalPrices(prices);
    for (int r : ret) {
        cout << r << " ";
    }
    cout << endl;

}