namespace _1190._Reverse_Substrings_Between_Each_Pair_of_Parentheses
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution solution = new Solution();
            //string s = "(u(love)i)";
            //string s = "(ed(et(oc))el)";
            string s = "a(bcdefghijkl(mno)p)q";

            string result = solution.ReverseParentheses(s);
            Console.WriteLine(result);
        }
    }

    public class Solution
    {
        public string ReverseParentheses(string s)
        {
            Stack<int> stack = new Stack<int>();
            string result = "";

            foreach (char currChar in s)
            {
                if (currChar == '(')
                {
                    stack.Push(result.Length);
                }
                else if (currChar == ')')
                {
                    int start = stack.Pop();
                    result = result.Substring(0, start) + new string(result.Substring(start).Reverse().ToArray());
                }
                else
                {
                    result += currChar;
                }
            }
            return result;
        }
    }
}