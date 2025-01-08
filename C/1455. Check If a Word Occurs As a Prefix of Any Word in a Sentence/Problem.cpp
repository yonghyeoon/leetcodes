/*
* Problem URL : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
* 
* Example 1:
* Input: sentence = "i love eating burger", searchWord = "burg"
* Output: 4
* 
* Example 2:
* Input: sentence = "this problem is an easy problem", searchWord = "pro"
* Output: 2
* 
* Example 3:
* Input: sentence = "i am tired", searchWord = "you"
* Output: -1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<pair<int, int>> emptyIndex;

        int start = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                emptyIndex.push_back({ start, i - 1 });
                start = i + 1;
            }
        }
        emptyIndex.push_back({ start, sentence.size() - 1 });


        for (int i = 0; i < emptyIndex.size(); i++) {
            int word_size = emptyIndex[i].second - emptyIndex[i].first + 1;
            if (word_size < searchWord.size()) {
                continue;
            }

            string temp = sentence.substr(emptyIndex[i].first, searchWord.size());
            if (temp == searchWord) {
                return i + 1;
            }
        }

        return -1;
    }
};

int main() {
    // string sentence = "i love eating burger";
    // string searchWord = "burg";

    // string sentence = "this problem is an easy problem";
    // string searchWord = "pro";

    string sentence = "i am tired";
    string searchWord = "you";

    Solution solution = Solution();
    int result = solution.isPrefixOfWord(sentence = sentence, searchWord = searchWord);
    cout << result << endl;

    return 0;
}