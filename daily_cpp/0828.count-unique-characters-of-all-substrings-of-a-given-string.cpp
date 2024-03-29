/* 828. 统计子串中的唯一字符
困难
相关标签
相关企业
我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。

例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。

本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。输入用例保证返回值为 32 位整数。

注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。



示例 1：

输入: s = "ABC"
输出: 10
解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
     其中，每一个子串都由独特字符构成。
     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
示例 2：

输入: s = "ABA"
输出: 8
解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
示例 3：

输入：s = "LEETCODE"
输出：92


提示：

1 <= s.length <= 105
s 只包含大写英文字符 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /* 对于下标为 i 的字符 c_i，当它在某个子字符串中仅出现一次时，它会对这个子字符串统计唯一字符时有贡献。只需对每个字符，计算有多少子字符串仅包含该字符一次即可。 */
    int uniqueLetterString(string s)
    {
        unordered_map<char, vector<int>> index;
        /* 统计字符出现时的索引 */
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i]].emplace_back(i);
        }

        int res = 0;
        for (auto &&[_, arr] : index)
        {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++)
            {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "ABC";
    Solution slt;
    cout << slt.uniqueLetterString(s) << endl;
    return 0;
}
