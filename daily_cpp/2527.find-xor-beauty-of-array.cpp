/* 2527. 查询数组 Xor 美丽值
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的整数数组 nums 。

三个下标 i ，j 和 k 的 有效值 定义为 ((nums[i] | nums[j]) & nums[k]) 。

一个数组的 xor 美丽值 是数组中所有满足 0 <= i, j, k < n  的三元组 (i, j, k) 的 有效值 的异或结果。

请你返回 nums 的 xor 美丽值。

注意：

val1 | val2 是 val1 和 val2 的按位或。
val1 & val2 是 val1 和 val2 的按位与。


示例 1：

输入：nums = [1,4]
输出：5
解释：
三元组和它们对应的有效值如下：
- (0,0,0) 有效值为 ((1 | 1) & 1) = 1
- (0,0,1) 有效值为 ((1 | 1) & 4) = 0
- (0,1,0) 有效值为 ((1 | 4) & 1) = 1
- (0,1,1) 有效值为 ((1 | 4) & 4) = 4
- (1,0,0) 有效值为 ((4 | 1) & 1) = 1
- (1,0,1) 有效值为 ((4 | 1) & 4) = 4
- (1,1,0) 有效值为 ((4 | 4) & 1) = 0
- (1,1,1) 有效值为 ((4 | 4) & 4) = 4
数组的 xor 美丽值为所有有效值的按位异或 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5 。
示例 2：

输入：nums = [15,45,20,2,34,35,5,44,32,30]
输出：34
解释：数组的 xor 美丽值为 34 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109 */
#include "../tools/func.h"
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /* TLE */
    int xorBeautyTLE(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                for (int k = 0; k < n; k++)
                {
                    ans ^= (nums[i] | nums[j]) & nums[k];
                }
            }
        }
        return ans;
    }

    int xorBeautyTLE2(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        vector<int> or_result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                or_result.push_back(nums[i] | nums[j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < or_result.size(); j++)
            {
                ans ^= or_result[j] & nums[i];
            }
        }
        return ans;
    }

    int xorBeauty(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
