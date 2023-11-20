/* 53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。



示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23


提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104

 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, max_ans = nums[0];
        for (auto &x : nums)
        {
            pre = max(pre + x, x);
            max_ans = max(pre, max_ans);
        }
        return max_ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution slt;
    cout << slt.maxSubArray(nums) << endl;
    return 0;
}
