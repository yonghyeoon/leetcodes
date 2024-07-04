// See https://aka.ms/new-console-template for more information

using _2181._Merge_Nodes_in_Between_Zeros;

Solution solution = new Solution();
// example 1
//ListNode head = new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0))))))));
// example 2
ListNode head = new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(0))))))));
ListNode result = solution.MergeNodes(head);

while (result != null)
{
    Console.WriteLine(result.val);
    result = result.next;
}

namespace _2181._Merge_Nodes_in_Between_Zeros
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
    public class Solution
    {
        public ListNode MergeNodes(ListNode head)
        {
            ListNode curr = head.next;
            ListNode nextSum = curr;

            while (nextSum != null)
            {
                int sum = 0;
                while (nextSum.val != 0)
                {
                    sum += nextSum.val;
                    nextSum = nextSum.next;
                }

                curr.val = sum;
                nextSum = nextSum.next;
                curr.next = nextSum;
                curr = curr.next;
            }

            return head.next;
        }
    }
}