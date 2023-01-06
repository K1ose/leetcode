/* 2180. 统计各位数字之和为偶数的整数个数
给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。

正整数的 各位数字之和 是其所有位上的对应数字相加的结果。



示例 1：

输入：num = 4
输出：2
解释：
只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。
示例 2：

输入：num = 30
输出：14
解释：
只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是：
2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。

30 14
31 15
32 15
33 16
34 16
35 17
36 17
37 18
38 18
39 19
40 20
41 20
42 21
提示：

1 <= num <= 1000 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* 暴力枚举 */
    // O[num * lg(num)]
    int countEven_brute_force(int num)
    {
        int count = 0;
        for (int i = 1; i <= num; i++)
        {
            int x = i;
            int sum = 0;
            while (x)
            {
                sum += x % 10; /* 获得最后一位数的累加 */
                x /= 10;       /* 每次移除最后一位数 */
            }
            if (sum % 2 == 0) /* 各位累加和为偶数 */
                count++;
        }
        return count;
    }

    /* O[lg(num)] */
    int countEven(int num)
    {
        int sum = 0;
        int temp_num = num;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }

        if (sum % 2 == 0)
            return temp_num / 2;
        else
        {
            return (temp_num + 1) / 2 - 1;
        }
    }
};

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    Solution slt;
    cout << slt.countEven(num) << endl;
    return 0;
}
