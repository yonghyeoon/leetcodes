// Source: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int cnt = 0;
        for (int i = 0; i < seats.size(); i++) {
            cnt += abs(seats[i] - students[i]);
        }

        return cnt;
    }
};

int main() {
	vector<int> seats = {3,1,5};
	vector<int> students = {2,7,4};
	Solution solution;
	cout << solution.minMovesToSeat(seats, students) << endl;
	return 0;
}