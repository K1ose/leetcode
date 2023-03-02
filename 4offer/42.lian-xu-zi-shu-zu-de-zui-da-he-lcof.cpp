/* 剑指 Offer 42. 连续子数组的最大和

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。



示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。



提示：

    1 <= arr.length <= 10^5
    -100 <= arr[i] <= 100

注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        /* f(i)=max{f(i−1)+nums[i],nums[i]} */
        int pre = 0, max_ans = nums[0];
        for (auto &x : nums)
        {
            /* x 即为 nums[i], pre 即为 f(i) = max(f(i-1)+nums[i],nums[i])  */
            pre = max(pre + x, x);
            max_ans = max(pre, max_ans);
        }
        return max_ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
