/* 15. 三数之和
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。


提示：

3 <= nums.length <= 3000
-105 <= nums[i] <= 105 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        /* 排序 + 双指针 */
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        /* i 指针从头开始遍历 */
        for (int i = 0; i < size; i++)
        {
            /* 和上次枚举的数不一样 */
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            /* k指针指向末尾 */
            int k = size - 1;
            /* 相反数，使得 nums[j] + nums[k] == op，从而求得三数之和为0 */
            int op = -nums[i];

            /* j 指针与 i 指针相邻，从 i 指针后开始遍历 */
            for (int j = i + 1; j < size; j++)
            {
                /* 和上次枚举的数不一样 */
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                /* 保证j在k指针之前，并且如果相加的值大于op，说明k指针的数太大了，向前寻找较小值*/
                while (j < k && nums[j] + nums[k] > op)
                    --k;
                /* 如果j和k指针重合，则退出对j指针的遍历 */
                if (j == k)
                    break;
                if (nums[j] + nums[k] == op)
                    /* 通过vector的栈操作将目标数组压入ans中 */
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution slt;

    vector<vector<int>> ans;
    ans = slt.threeSum(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
