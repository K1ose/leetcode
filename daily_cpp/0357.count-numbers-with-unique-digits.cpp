/*
2022-4-11 https://leetcode-cn.com/problems/count-numbers-with-unique-digits/

357. 统计各位数字都不同的数字个数
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。

示例 1：

输入：n = 2
输出：91
解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。
示例 2：

输入：n = 0
输出：1
 

提示：

0 <= n <= 8
 */

/*
F(1) = F(0) + f(1)
F(2) = F(1) + f(2)
F(3) = F(2) + f(3)
...
F(n) = F(n-1) + f(n)
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        int *F = new int[n + 1];
        F[0] = 1;
        F[1] = 10;
        for (int i = 2; i <= n; i++)
        {
            int cur = (F[i - 1] - F[i - 2]) * (10 - (i - 1)); // 排列组合，首位数不取 0 其他位数可以取 0，下一位比前一位取法少一种
            F[i] = F[i - 1] + cur;
        }
        return F[n];
    }
};

int main()
{
    int n = 8;
    Solution S;
    cout << S.countNumbersWithUniqueDigits(n);
}