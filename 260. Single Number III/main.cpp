#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;

        int bitmask = 0;
        for (int num : nums) {
            bitmask ^= num;
        }

        cout << "bitmask : " << bitmask << endl;
        cout << "-bitmask : " << (-bitmask) << endl;

        // 
        int diff = bitmask & (-bitmask);

        cout << "diff : " << diff << endl;

        int x = 0;
        for (int num : nums) {
            if ((num & diff) != 0) {
                x ^= num;
            }
        }

        ans.push_back(x);
        ans.push_back(x ^ bitmask);

        return ans;
    }
};

int main() {

    //vector<int> nums = { 1, 2, 1, 3, 2, 5 };
    vector<int> nums = { -1,0 };
    vector<int> result;
    Solution a = Solution();
    result = a.singleNumber(nums);

    for (int res : result) {
        cout << res << endl;
    }

    return 0;

    /*
    *
    Example 1:
        Input: nums = [1,2,1,3,2,5]
        Output: [3,5]
        Explanation:  [5, 3] is also a valid answer.

    Example 2:
        Input: nums = [-1,0]
        Output: [-1,0]

    Example 3:
        Input: nums = [0,1]
        Output: [1,0]
    */

}