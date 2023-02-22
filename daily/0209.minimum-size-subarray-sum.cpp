/* 209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：

输入：target = 4, nums = [1,4,4]
输出：1

示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0



提示：

    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 105



进阶：

    如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* brute force: time limit */
    int minSubArrayLen_brute_force(int target, vector<int> &nums)
    {
        int n = nums.size();
        int res = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            int cur_sum = 0;
            for (int j = i; j < n; j++)
            {
                cur_sum += nums[j];
                if (cur_sum >= target)
                {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        if (res == INT32_MAX)
            return 0;
        return res;
    }

    /* double ptr */
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, sum = 0;
        int n = nums.size();
        int res = n + 1;
        for (int right = 0; right < n; right++)
        {
            /* 把向右遍历时纳入的元素nums[right]加入 */
            sum += nums[right];

            /* 如果此时发现减去左端点后还是大于target,则可以减去该值，并移动左指针 */
            while (sum - nums[left] >= target)
            {
                sum -= nums[left];
                left++;
            }

            if (sum >= target)
            {
                res = min(res, right - left + 1);
            }
        }
        return res <= n ? res : 0;
    }
};

int main(int argc, char const *argv[])
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution slt;
    cout << slt.minSubArrayLen(target, nums) << endl;
    return 0;
}
