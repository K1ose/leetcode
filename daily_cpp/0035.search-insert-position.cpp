/* 35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。



示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4


提示:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 为 无重复元素 的 升序 排列数组
-104 <= target <= 104
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /// @brief 暴力模拟
    /// @param nums - 待插入的已排序数组
    /// @param target - 待插入的目标元素
    /// @return 如果已经存在，则返回下标，不存在则返回插入位置的下标
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
                return i;
        }
        return 0;
    }

    /// @brief 二分查找
    /// @param nums - 待搜索数组
    /// @param target - 待插入元素
    /// @return 返回元素下标或对应的插入位置
    int searchInsert_binary(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int mid, ans = high + 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;

            else
            {
                ans = mid;
                high = mid - 1;
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

    int target;
    cin >> target;

    Solution slt;
    cout << slt.searchInsert_binary(nums, target) << endl;
    return 0;
}
