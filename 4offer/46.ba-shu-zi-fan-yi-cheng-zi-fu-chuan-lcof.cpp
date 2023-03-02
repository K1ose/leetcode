/* 剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。



示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"



提示：

    0 <= num < 231

 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    合法的转换必须要求在0~25之间，那么每次截取的字符串的长度是<=2的，并且需要判断其是否在0~25之间。
    因此类似于台阶问题，可以截取一位，也可以截取两位，截取两位的时候需要进行判断即可 */
    int translateNum(int num)
    {
        string num_str = to_string(num);
        int n = num_str.size();
        /* dp[i] 为到第i位数字时可用字母翻译的数目 */
        vector<int> dp(n);
        dp[0] = 1;
        /* 用于判断第一个数字是否为0 */

        for (int i = 1; i < dp.size(); i++)
        {
            if (i > 1)
            {
                int cur = stoi(num_str.substr(i - 1, 2));
                if (cur > 9 && cur < 26)
                {
                    dp[i] += dp[i - 1] + dp[i - 2];
                }
                else
                {
                    dp[i] += dp[i - 1];
                }
            }
            else
            {
                int cur = stoi(num_str.substr(0, 2));
                if (cur < 26 && cur > 9)
                {
                    dp[1] += dp[0] + 1;
                }
                else
                {
                    dp[1] += dp[0];
                }
            }
        }

        /* 返回最后一个元素 */
        return dp.back();
    }

    int translateNum_dg(int num)
    {
        if (num < 10)
            return 1;
        if (num % 100 > 9 && num % 100 < 26)
            return translateNum(num / 10) + translateNum(num / 100);
        return translateNum(num / 10);
    }

    /* 滚动数组优化空间 */
    int translateNum_official(int num)
    {
        string src = to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i)
        {
            p = q;
            q = r;
            r = 0;
            r += q;
            if (i == 0)
            {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10")
            {
                r += p;
            }
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
