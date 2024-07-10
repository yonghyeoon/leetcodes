Solution solution = new Solution();
// example1
//int res = solution.MinOperations(new string[] { "d1/", "d2/", "../", "d21/", "./" });

// exmaple2
//int res = solution.MinOperations(new string[] { "d1/", "d2/", "./", "d3/", "../", "d31/" });

// exmaple3
int res = solution.MinOperations(new string[] { "d1/", "../", "../", "../" });
Console.WriteLine(res);

public class Solution
{
    public int MinOperations(string[] logs)
    {

        int length = logs.Length;
        int result = 0;

        for (int i = 0; i < length; i++)
        {
            if (logs[i] == "./")
            {
                continue;
            }

            if (logs[i] == "../")
            {
                if (result > 0) { result--; }
            }
            else { result++; }
        }

        return result;
    }
}
