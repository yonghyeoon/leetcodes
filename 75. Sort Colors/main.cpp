// Source: https://leetcode.com/problems/sort-colors/

#include <vector>
#include <iostream>

using namespace std;

#define MY_ANSWER

#ifdef MY_ANSWER
void customSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void sortColors(vector<int>& nums) {
    customSort(nums);
}

#else // Dutch National Flag problem
void sortColors(vector<int>& nums) {
    int p0 = 0, curr = 0, p2 = nums.size() - 1;

    while (curr <= p2) {
        if (nums[curr] == 0) {
            swap(nums[curr++], nums[p0++]);
        }
        else if (nums[curr] == 2) {
            swap(nums[curr], nums[p2--]);
        }
        else {
            curr++;
        }
    }
}
#endif

int main() {
	vector<int> nums = {2,0,2,1,1,0};
	sortColors(nums);
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}