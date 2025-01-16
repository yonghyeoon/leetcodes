/*

Problem URL : https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.


Example 1:
Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
 

Constraints:
ㆍ 1 <= nums1.length, nums2.length <= 105
ㆍ 0 <= nums1[i], nums2[j] <= 109

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int num1_size =  nums1.size();
        int num2_size =  nums2.size();

        int answer = 0;
        int x = 0;
        for (int i=0; i < num1_size; i++) {
            x ^= nums1[i];
        }

        if (num1_size % 2 == 1) {
            for (int j=0; j < num2_size; j++) {
                answer ^= x ^ nums2[j];
            }
        }
        else {
            answer = (num2_size % 2 == 0) ? 0 : x;            
        }

        return answer;
    }
};

int main(void){

    // Example 1
    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {10,2,5,0};

    // Example 2
    // vector<int> nums1 = {1,2};
    // vector<int> nums2 = {3,4};

    Solution solution = Solution();
    int result = solution.xorAllNums(nums1, nums2);
    cout << result << endl;
}
