namespace _1213._Intersection_of_Three_Sorted_Arrays
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution solution = new();

            int[] arr1 = [1, 2, 3, 4, 5];
            int[] arr2 = [1, 2, 5, 7, 9];
            int[] arr3 = [1, 3, 4, 5, 8];

            IList<int> ret = solution.ArraysIntersection(arr1, arr2, arr3);
            List<int> temp = ret.ToList();

            foreach (int val in temp)
            {
                Console.WriteLine(val);
            }
        }
    }

    public class Solution
    {
        public IList<int> ArraysIntersection(int[] arr1, int[] arr2, int[] arr3)
        {
            IList<int> ans = new List<int>();
            SortedDictionary<int, int> Counter = new();

            foreach (int val in arr1)
            {
                if (Counter.ContainsKey(val)) { Counter[val]++; }
                else { Counter.Add(val, 1); }
            }

            foreach (int val in arr2)
            {
                if (Counter.ContainsKey(val)) { Counter[val]++; }
                else { Counter.Add(val, 1); }
            }

            foreach (int val in arr3)
            {
                if (Counter.ContainsKey(val)) { Counter[val]++; }
                else { Counter.Add(val, 1); }
            }

            foreach (KeyValuePair<int, int> item in Counter)
            {
                if (item.Value == 3)
                {
                    ans.Add(item.Key);
                }
            }

            return ans;
        }
    }
}
