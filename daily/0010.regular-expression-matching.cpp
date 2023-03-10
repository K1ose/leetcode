/* 10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


示例 1：

输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa", p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab", p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。


提示：

1 <= s.length <= 20
1 <= p.length <= 30
s 只包含从 a-z 的小写字母。
p 只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void print_matrix(vector<vector<int>> matrix, int m, int n)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    bool isMatch(string s, string p)
    {
        /* 动态规划 */
        /* 枚举情况：
        用 f[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配
        1. 如果p的第j个字符是一个小写字母，那么必须在s中匹配一个相同的小写字母，即：
                    f[i][j]
                |= f[i-1]f[j-1], s[i]=p[j]
                |= false, s[i]!=p[j]
        2. 如果p的第j个字符是*，那么就对p的第j-1个字符匹配任意自然数次。
           本质上只会有两种情况：
            1. 匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；
            2. 不匹配字符，将该组合扔掉，不再进行匹配。

            - 在匹配0次时，有： f[i][j] = f[i][j-2] 相当于我们浪费了一个字符+星号的组合，没有匹配s中任何的字符
            - 在匹配1次时，有： f[i][j] = f[i-1][j-2], if s[i] = p[j-1]
            - 在匹配2次时，有： f[i][j] = f[i-2][j-2], if s[i-1] = s[i] = p[j-1]
            - 在匹配3次时，有： f[i][j] = f[i-3][j-2], if s[i-2] = s[i-1] = s[i] = p[j-1]
            ...
            - 在匹配n次时，有： f[i][j] = f[i-n][j-2], if s[i-n] = s[i-n-1] = ... = s[i] = p[j-1]
            基于上述两种，得出状态转移方程。

            f[i][j]
            = f[i-1]f[j] or f[i][j-2]   ,s[i] = p[j-1]
            = f[i][j-2]                 ,s[i] != p[j-1]

        得出总状态转移方程：
        f[i][j]
        = if(p[j] != '*')
            = f[i-1][j-1]   , if matches(s[i], p[j])
            = false         , if otherwise
        = otherwise
            = f[i-1][j] or f[i][j-2]    , if matches(s[i],p[j-1])
            = f[i][j-2]                 , if otherwise
        */

        int s_len = s.length();
        int p_len = p.length();

        auto my_match = [&](int i, int j)
        {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(s_len + 1, vector<int>(p_len + 1));
        f[0][0] = true;
        for (int i = 0; i <= s_len; ++i)
            for (int j = 1; j <= p_len; ++j)
            {
                /* 如果p[j-1]='*' */
                if (p[j - 1] == '*')
                {
                    /* 如果p[j-1]和s[i]不匹配，则相当于浪费了一个'*'+字符的组合 */
                    f[i][j] |= f[i][j - 2];

                    /* 如果p[j-1]和s[i]匹配 */
                    if (my_match(i, j - 1))
                        f[i][j] |= f[i - 1][j];
                }
                /* 如果p[j-1]!='*' */
                else
                {
                    /* 如果s[i]=p[j] */
                    if (my_match(i, j))
                        f[i][j] |= f[i - 1][j - 1];
                }
            }
        // print_matrix(f, s_len, p_len);
        return f[s_len][p_len];
    }
};

int main()
{
    Solution slt;
    string s, p;
    cin >> s >> p;
    if (slt.isMatch(s, p))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}