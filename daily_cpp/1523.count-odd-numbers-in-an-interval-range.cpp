/* 1523. 在区间范围内统计奇数数目
简单
相关标签
相关企业
提示
给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。



示例 1：

输入：low = 3, high = 7
输出：3
解释：3 到 7 之间奇数数字为 [3,5,7] 。
示例 2：

输入：low = 8, high = 10
输出：1
解释：8 到 10 之间奇数数字为 [9] 。


提示：

0 <= low <= high <= 10^9 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        if (low == high)
        {
            if (low % 2 == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int ans = 0;

        if (high % 2 == 1)
        {
            ans += (high - low - 1) / 2;
        }

        else
        {
            ans += (high - low) / 2;
        }

        return (low % 2) + (high % 2) + ans;
    }
};

int main(int argc, char const *argv[])
{
    int low = 8, high = 10;
    Solution slt;
    cout << slt.countOdds(low, high) << endl;
    return 0;
}
