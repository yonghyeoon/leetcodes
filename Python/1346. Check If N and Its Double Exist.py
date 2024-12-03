from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        for i in range(len(arr)):
            if arr[i] % 2 != 0:
                continue
            
            for j in range(len(arr)):
                if i == j:
                    continue

                if arr[i] == 2 * arr[j]:
                    return True


        return False
    

# Example 1:
# Input: arr = [10,2,5,3]
# Output: true
arr = [10,2,5,3]

# Example 2:
# Input: arr = [3,1,7,11]
# Output: false
arr = [3,1,7,11]

solution = Solution()
result = solution.checkIfExist(arr)
print(result)