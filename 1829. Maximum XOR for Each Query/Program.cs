namespace _1829._Maximum_XOR_for_Each_Query
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution solution = new();

            // Example1 : nums = [0, 1, 1, 3], maximumBit = 2 
            // int[] nums = new int[4] { 0, 1, 1, 3 };
            // int maximumBit = 2;

            // Example2 : nums = [2,3,4,7], maximumBit = 3
            // int[] nums = new int[4] { 2, 3, 4, 7 };
            // int maximumBit = 3;

            // Example3 : nums = [0,1,2,2,5,7], maximumBit = 3
            int[] nums = [ 0, 1, 2, 2, 5, 7 ];
            int maximumBit = 3;

            int[] result = solution.GetMaximumXor(nums, maximumBit);
            foreach (int i in result) { Console.Write($"{i} "); }
        }
    }

    public class Solution
    {
        public int[] GetMaximumXor(int[] nums, int maximumBit)
        {
            int[] ans = new int[nums.Length];
            int target = (int)Math.Pow(2, maximumBit) - 1;

            int xor_sum = 0;
            int len = nums.Length - 1;
            for (int i = 0; i <= len; i++)
            {
                xor_sum ^= nums[i];
                ans[len - i] = xor_sum ^ target;
            }

            return ans;
        }
    }
}
