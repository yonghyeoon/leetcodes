#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int cnt = 0;

        vector<int> expected = heights;

        sort(expected.begin(), expected.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                cnt++;
            }
        }
        return cnt;

    }
};

int main() {
	Solution solution;
	vector<int> heights = {1,1,4,2,1,3};
	cout << solution.heightChecker(heights) << endl;
	return 0;
}

/*
Example 1:
    Input: heights = [1, 1, 4, 2, 1, 3]
    Output : 3
    Explanation :
    heights : [1, 1, 4, 2, 1, 3]
    expected : [1, 1, 1, 2, 3, 4]
    Indices 2, 4, and 5 do not match.

Example 2 :
    Input : heights = [5, 1, 2, 3, 4]
    Output : 5
    Explanation :
    heights : [5, 1, 2, 3, 4]
    expected : [1, 2, 3, 4, 5]
    All indices do not match.

Example 3 :
    Input : heights = [1, 2, 3, 4, 5]
    Output : 0
    Explanation :
    heights : [1, 2, 3, 4, 5]
    expected : [1, 2, 3, 4, 5]
    All indices match.
*/