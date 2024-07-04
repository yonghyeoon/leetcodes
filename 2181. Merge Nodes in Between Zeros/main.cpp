#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;

        int sum = 0;
        while (curr) {
            if (curr->val == 0 && sum > 0) {
                v.push_back(sum);
                sum = 0;
            }
            else if (curr->val > 0) {
                sum += curr->val;
            }

            curr = curr->next;
        }

        ListNode* node = new ListNode(0);
        ListNode* temp = node;
        for (int n : v) {
            ListNode* curr = new ListNode(n);
            temp->next = curr;
            temp = temp->next;
        }

        return node->next;
    }
};

int main() {
    Solution solution;
    //ListNode* node = solution.mergeNodes(new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(0)))))))));
    ListNode* node = solution.mergeNodes(new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0)))))))));

    while (node) {
		std::cout << node->val << " ";
		node = node->next;
	}

    return 0;

}