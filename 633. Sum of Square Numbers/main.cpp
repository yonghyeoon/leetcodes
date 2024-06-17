// Source: https://leetcode.com/problems/sum-of-square-numbers/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {

        unsigned long start = 0;
        unsigned long end = (int)sqrt(c);

        while (start <= end) {
            unsigned long square = (start * start) + (end * end);
            if (square == c) return true;
            else if (square > c) end--;
            else start++;
        }

        return false;
    }
};

int main() {
	Solution solution;

    cout << solution.judgeSquareSum(5) << endl;
    cout << solution.judgeSquareSum(3) << endl;
    cout << solution.judgeSquareSum(4) << endl;
    cout << solution.judgeSquareSum(2) << endl;
    cout << solution.judgeSquareSum(1) << endl;
    cout << solution.judgeSquareSum(0) << endl;

	return 0;
}