/*

You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 
Constraints:
• 1 <= s1.length, s2.length <= 100
• s1.length == s2.length
• s1 and s2 consist of only lowercase English letters.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool areAlmostEqual(char* s1, char* s2) {
    int len = strlen(s1);
    int freq1[26] = {0};
    int freq2[26] = {0};

    int diff_count = 0;
    for (int i=0; i < len; i++) {
        if (s1[i] != s2[i]) {
            diff_count++;
        }

        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (diff_count == 0) { return true; }
    if (diff_count != 2) { return false; }
    
    for (int i=0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    
    return true;
}

int main(void){
    // Example 1
    // char* s1 = "bank";
    // char* s2 = "kanb";

    // Example 2
    // char* s1 = "attack";
    // char* s2 = "defend";

    // Example 3
    char* s1 = "kelb";
    char* s2 = "kelb";

    bool result = areAlmostEqual(s1, s2);
    printf("%s", result ? "true" : "false");

    return 0;
}
