/* 1124. 表现良好的最长时间段
给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。



示例 1：

输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。
示例 2：

输入：hours = [6,6,6]
输出：0


提示：

1 <= hours.length <= 104
0 <= hours[i] <= 16 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int sum = 0, ans = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < hours.size(); i++)
        {
            sum += hours[i] > 8 ? 1 : -1;
            /* sum>0 表示出现了表现良好的时间段，需要记录这个区间的最长长度 */
            if (sum > 0)
            {
                /* 只要sum>0，记录最长长度 */
                ans = max(sum, i + 1);
            }
            /* 如果不是表现良好的时间段 */
            else
            {
                if (ump.count(sum - 1))
                {
                    ans = max(ans, i - ump[sum - 1]);
                }
            }
            /* 记录当前前缀和 */
            if (!ump.count(sum))
            {
                ump[sum] = i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
