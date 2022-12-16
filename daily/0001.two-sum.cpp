/*
2022/6/25
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。



示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]


提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // O(n) = N^2 272ms
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // hash Map => O(n) = N 12 ms
    vector<int> hashMapTwoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            // using hashtable.find() to search the number
            auto it = hashtable.find(target - nums[i]);
            // if we find the number matching "target-x", then return it->VALUE and i
            if (it != hashtable.end())
            {
                // it->first is KEY, it->second is VALUE
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
            // KEY = number, VALUE = index
        }
        return {};
    }
};

void display(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {3, 2, 4};
    Solution test;
    int target;
    cin >> target;
    vector<int> arr(2);
    arr = test.hashMapTwoSum(nums, target);
    display(arr);
}
