#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> temp;
        map<int, int> mp;

        for (int it : arr1) {
            if (find(arr2.begin(), arr2.end(), it) - arr2.begin() < arr2.size()) {
                mp[it]++;
            }
            else {
                temp.push_back(it);
            }
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for (auto a2 : arr2) {
            vector<int> v(mp[a2], a2);
            ans.insert(ans.end(), v.begin(), v.end());
        }

        ans.insert(ans.end(), temp.begin(), temp.end());

        return ans;
    }
};

int main() {
	Solution solution;
	vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2 = {2,1,4,3,9,6};
	vector<int> ans = solution.relativeSortArray(arr1, arr2);
	for (int it : ans) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}