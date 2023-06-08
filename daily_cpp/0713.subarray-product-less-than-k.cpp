/* 713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。


示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。

示例 2：

输入：nums = [1,2,3], k = 0
输出：0



提示:

    1 <= nums.length <= 3 * 104
    1 <= nums[i] <= 1000
    0 <= k <= 106

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* double ptr */
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 0)
        {
            return 0;
        }
        int left = 0, sum = 1, res = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++)
        {
            sum *= nums[right];
            while (left <= right && sum >= k)
            {
                sum /= nums[left];
                left++;
            }
            /* 符合<k的子数组中的每个数也都符合<k */
            res += right - left + 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 1};
    int k = 1;
    Solution slt;
    cout << slt.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}
