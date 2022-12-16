/* 704. 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1


提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* 暴力查找 */
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                return i;
        return -1;
    }

    /// @brief 二分查找
    /// @param nums - 给定的待查找数组
    /// @param target - 查找目标元素
    /// @return 目标元素存在则返回其下标，不存在则返回-1
    int search_binary(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;

            else if (target < nums[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cin >> target;

    Solution slt;
    cout << slt.search_binary(nums, target) << endl;
    return 0;
}
