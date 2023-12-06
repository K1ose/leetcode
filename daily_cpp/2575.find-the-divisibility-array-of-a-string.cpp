/* 2575. 找出字符串的可整除数组
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。



示例 1：

输入：word = "998244353", m = 3
输出：[1,1,0,0,0,1,1,0,0]
解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
示例 2：

输入：word = "1010", m = 10
输出：[0,1,0,1]
解释：仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。


提示：

1 <= n <= 105
word.length == n
word 由数字 0 到 9 组成
1 <= m <= 109 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.size();
        int x = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            x = (word[i] - '0' + x * 10) % m;
            if (x % m == 0)
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "998244353";
    int m = 3;
    Solution slt;
    print_vec1d_arr(slt.divisibilityArray(s, m));
    return 0;
}
