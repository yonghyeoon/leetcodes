/*
* Example 1:
* Input: arr = [10,2,5,3]
* Output: true
*
* Example 2:
* Input: arr = [3,1,7,11]
* Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                continue;
            }

            for (int j = 0; j < arr.size(); j++) {
                if (i == j) {
                    continue;
                }

                if (arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    //vector<int> arr = { 10,2,5,3 };
    vector<int> arr = { 3,1,7,11 };

    Solution solution = Solution();
    bool result = solution.checkIfExist(arr);
    string ans = result ? "true" : "false";

    cout << ans << endl;

    return 0;
}