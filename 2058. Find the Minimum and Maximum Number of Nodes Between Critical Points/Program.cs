// See https://aka.ms/new-console-template for more information
Solution soulotion = new Solution();

// example 1
//int[] result = soulotion.NodesBetweenCriticalPoints(new ListNode(3, new ListNode(1)));

// example 2
//int[] result = soulotion.NodesBetweenCriticalPoints(new ListNode(5, new ListNode(3, new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(1, new ListNode(2))))))));

// example 3
int[] result = soulotion.NodesBetweenCriticalPoints(new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(7))))))))));
Console.WriteLine(result[0]);
Console.WriteLine(result[1]);

public class Solution
{
    public int[] NodesBetweenCriticalPoints(ListNode head)
    {
        int[] ans = new int[2] { -1, -1 };

        int minDistance = 100000;
        ListNode prev = head;
        ListNode curr = head.next;

        int prevCrtIdx = 0;
        int firstCrtIdx = 0;
        int currIdx = 1;

        while (curr.next != null)
        {
            if ((curr.val > prev.val && curr.val > curr.next.val) || (curr.val < prev.val && curr.val < curr.next.val))
            {
                if (firstCrtIdx == 0)
                {
                    firstCrtIdx = currIdx;
                    prevCrtIdx = currIdx;
                }
                else
                {
                    minDistance = Math.Min(minDistance, currIdx - prevCrtIdx);
                    prevCrtIdx = currIdx;
                }
            }

            prev = prev.next;
            curr = curr.next;
            currIdx++;
        }

        if (minDistance == 100000) { return ans; }

        ans[0] = minDistance;
        ans[1] = prevCrtIdx - firstCrtIdx;

        return ans;
    }
}



public class ListNode
{

    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
        this.val = val;
        this.next = next;
    }
}
