/* 剑指 Offer 64. 求1+2+…+n

求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。



示例 1：

输入: n = 3
输出: 6

示例 2：

输入: n = 9
输出: 45



限制：

    1 <= n <= 10000

 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    int sumNums_illegal(int n)
    {
        /* 如果没有限制的话 */
        if (n == 0)
        {
            return 0;
        }
        return n + sumNums(n - 1);
    }

    int sumNums(int n)
    {
        /* 利用逻辑运算符的短路性质来找到递归出口:
        对于 A && B 这个表达式，如果 A 表达式返回 False ，那么 A && B 已经确定为 False ，此时不会去执行表达式 B */
        n && (n += sumNums(n - 1));
        return n;
    }

    /* 快速乘 */
    /* A*B用加法和位运算替代。其实就是将 B 二进制展开，如果 B 的二进制表示的第 i 位为 1，那么这一位对最后结果的贡献就是 A∗(1<<i) ，即 A<<i。我们遍历 B 二进制展开下的每一位，将所有贡献累加起来就是最后的答案，这个方法也被称作「俄罗斯农民乘法」，即：将被乘数除以2, 乘数乘以2, 如果被乘数除以2以后有余数(余数为1), 则将乘数累加到结果中. */
    int quickMulti(int A, int B)
    {
        int ans = 0;
        for (; B; B >>= 1) /* 遍历B的每一位，每次B除以2 */
        {
            if (B & 1) /* 如果当前最后一位为 1 */
            {
                ans += A; /* 累加 */
            }
            A <<= 1; /* 每次A乘以2 */
        }
        return ans;
        /* 上述代码可以用下面代码替代 */
        /*
        int ans = 0, A = n, B = n + 1;
        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;
        ...
        (B & 1) && (ans += A);
        ...
         */
    }
};

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    Solution slt;
    cout << slt.quickMulti(a, b) << endl;
    return 0;
}
