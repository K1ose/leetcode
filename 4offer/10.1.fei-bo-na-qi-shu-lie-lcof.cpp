/* 剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。



示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5


提示：

0 <= n <= 100 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    递推公式：F(n) = F(n-1)+F(n-2)
    每一项的值为前两项的和
     */
    int fib(int n)
    {
        int mod = 1000000007;
        if (n < 2)
            return n;
        /* p、q记录为前两项 */
        int p = 0, q = 0, r = 1;
        /* 从2开始，2为fib(0) + fib(1) */
        for (int i = 2; i <= n; i++)
        {
            p = q;
            q = r;
            r = (p + q) % mod;
        }
        return r;
    }

    /* 下面是矩阵快速幂，复杂度为 O(logn) */
    /* 作者：LeetCode-Solution
    链接：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/solution/fei-bo-na-qi-shu-lie-by-leetcode-solutio-hbss/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */
    const int MOD = 1000000007;
    int fib_quick(int n)
    {
        if (n < 2)
        {
            return n;
        }
        vector<vector<long>> q{{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(q, n - 1);
        return res[0][0];
    }

    vector<vector<long>> pow(vector<vector<long>> &a, int n)
    {
        vector<vector<long>> ret{{1, 0}, {0, 1}};
        while (n > 0)
        {
            if (n & 1)
            {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>> &a, vector<vector<long>> &b)
    {
        vector<vector<long>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return c;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution slt;
    cout << slt.fib(n) << endl;
    return 0;
}
