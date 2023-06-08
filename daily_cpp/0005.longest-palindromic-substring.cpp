/* 5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。



示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"


提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // len: s的长度
        int len = s.size();
        int maxLen = 1;
        int begin = 0;
        // 长度为1的字符串的回文串即为本身
        if (len <= 1)
            return s;

        // 当长度大于1时
        // dp[i][j]表示s[i]->s[j], vector<vector<int>>为二维数组
        vector<vector<int>> dp(len, vector<int>(len));

        // 初始化，所有长度为1的字串都是回文串
        for (int i = 0; i < len; i++)
            dp[i][i] = true;

        // 递推求解
        // 从相邻两个字符开始比较(L=2)，一直循环到整个字符串的首尾比较
        for (int L = 2; L <= len; L++)
        {
            for (int i = 0; i < len; i++)
            {
                int j = L + i - 1;
                // 如果j越界，则跳出for循环
                if (j >= len)
                    break;
                // 如果比较的两个字符不相等，即不是dp[i][j](s[i]->s[j])不是回文串，标记为false
                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }

                // 如果相等
                else
                {
                    // 判断间隔是否小于3，即间隔为 1 或 两字符相邻，直接使dp[i][j]=true，即s[i]->s[j]为回文串
                    if (j - i < 3)
                    {
                        dp[i][j] = true;
                    }

                    // 如果间隔大于等于 2，则dp[i][j]=dp[i+1][j-1]，即当前s[i][j]是否为回文串取决于它们之间缩小一个区间后是否为回文串
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 只要 dp[i][j] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};