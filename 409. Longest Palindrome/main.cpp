#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        map<char, int> mp;

        if (s.size() == 1) return 1;

        for (char c : s) {
            mp[c]++;
        }

        bool is_odd = false;
        for (auto m : mp) {
            if (m.second % 2 == 0) {
                ans += m.second;
            }
            else {
                is_odd = true;
                ans += m.second - 1;
            }
        }

        if (is_odd) {
            return ans + 1;
        }

        return ans;
    }
};

int main() {
	string s = "abccccdd";
	Solution a = Solution();
	cout << a.longestPalindrome(s) << endl;

	return 0;
}

