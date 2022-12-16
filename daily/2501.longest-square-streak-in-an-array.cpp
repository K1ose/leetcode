/* 2501. 数组中最长的方波 显示英文描述
通过的用户数2819
尝试过的用户数3284
用户总通过次数2886
用户总提交次数7888
题目难度Medium
给你一个整数数组 nums 。如果 nums 的子序列满足下述条件，则认为该子序列是一个 方波 ：
    - 子序列的长度至少为 2 ，并且
    - 将子序列从小到大排序 之后 ，除第一个元素外，每个元素都是前一个元素的 平方 。
返回 nums 中 最长方波 的长度，如果不存在 方波 则返回 -1 。

子序列 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。



示例 1 ：

输入：nums = [4,3,6,16,8,2]
输出：3
解释：选出子序列 [4,16,2] 。排序后，得到 [2,4,16] 。
- 4 = 2 * 2.
- 16 = 4 * 4.
因此，[4,16,2] 是一个方波.
可以证明长度为 4 的子序列都不是方波。
示例 2 ：

输入：nums = [2,3,5,6,7]
输出：-1
解释：nums 不存在方波，所以返回 -1 。


提示：

2 <= nums.length <= 105
2 <= nums[i] <= 105 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    /// @brief 动态规划
    /// @param nums - 待检测数组
    /// @return
    int longestSquareStreak(vector<int> &nums)
    {
        /* 对数组进行排序 */
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.back() + 1);
        int ans = 0;

        for (auto &i : nums)
        {
            dp[i] = 1;
            int target = (int)sqrt(i);
            if (target * target == i)
                dp[i] = dp[target] + 1;
            ans = max(ans, dp[i]);
        }
        return ans > 1 ? ans : -1;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
