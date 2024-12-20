"""

Problem URL : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

Example 1:
Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]

Example 2:
Input: root = [7,13,11]
Output: [7,11,13]

Example 3:
Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]

"""

from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        lq = [[root.left, 1]]
        rq = [[root.right, 1]]

        while lq and rq:
            lnode, level = lq.pop()
            rnode, _ = rq.pop()

            if lnode == None:
                continue

            if level % 2 == 1:
                lnode.val, rnode.val = rnode.val, lnode.val

            if lnode.left != None:
                lq.append([lnode.left, level+1])
                lq.append([lnode.right, level+1])
                rq.append([rnode.right, level+1])
                rq.append([rnode.left, level+1])

        return root



# Example 1
# nodes = TreeNode(2, TreeNode(3, TreeNode(8), TreeNode(13)), TreeNode(5, TreeNode(21), TreeNode(34)))

# Example 2
# nodes = TreeNode(7, TreeNode(13), TreeNode(11))

# Example 3, [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
nodes = TreeNode(0, TreeNode(1, TreeNode(0, TreeNode(1), TreeNode(1)), TreeNode(0, TreeNode(1), TreeNode(1))), TreeNode(2, TreeNode(0, TreeNode(2), TreeNode(2)), TreeNode(0, TreeNode(2), TreeNode(2))))

solution = Solution()
ret_nodes = solution.reverseOddLevels(nodes)

result = []

# BFS를 위한 큐
queue = deque([ret_nodes])  # 큐에 루트 노드를 추가합니다.

while queue:
    node = queue.popleft()  # 큐의 첫 번째 노드를 가져옵니다.
    result.append(node.val)  # 현재 노드의 값을 결과 리스트에 추가합니다.

    # 왼쪽 자식과 오른쪽 자식을 큐에 추가합니다.
    if node.left:
        queue.append(node.left)
    if node.right:
        queue.append(node.right)

print(result)