/* 剑指 Offer 57. 和为s的两个数字

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。



示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]



限制：

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /* 观察到所有的数都是正数，且是递增的，所以可以不考虑大于target的数 */
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            while (nums[right] >= target)
            {
                right--;
            }
            if (nums[left] + nums[right] < target)
            {
                left++;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
