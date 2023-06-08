/*
2022-2-26
题目：增量元素之间的最大差值
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。

 

示例 1：

输入：nums = [7,1,5,4]
输出：4
解释：
最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
示例 2：

输入：nums = [9,4,3,2]
输出：-1
解释：
不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
示例 3：

输入：nums = [1,5,2,10]
输出：9
解释：
最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
 

提示：

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#define INT_MIN -2147483647 - 1
using namespace std;

class Solution
{
public:
    vector<int> createArray(int n)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        return nums;
    }
    int maximumDifference(vector<int> &nums)
    {
        // 由于需要求出最大差值，所以可以维护数组元素的最小值，通过寻找和维护最大差来得到答案
        int n = nums.size();
        int minValue = nums[0];
        int dp = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            dp = max(dp, nums[i] - minValue);  // 最大差值
            minValue = min(minValue, nums[i]); // 数组最小值
        }
        if (dp <= 0)
            return -1;
        return dp;
    }
};

int main()
{
    int t, n;
    cin >> t >> n;
    while (t--)
    {
        vector<int> nums(n);
        Solution test;
        nums = test.createArray(n);
        cout << test.maximumDifference(nums) << endl;
    }
    return 0;
}