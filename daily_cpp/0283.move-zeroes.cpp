/* 283. 移动零
简单
相关标签
相关企业
提示
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。



示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]


提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


进阶：你能尽量减少完成的操作次数吗？ */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right]) // 如果 nums[right] 不是 0，则交换左右
            {
                swap(nums[left], nums[right]);
                left++; // 向右遍历修改点
            }
            right++; // 向右遍历检索
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 0, 2, 3, 0, 0, 4, 0, 5, 6, 0, 7, 0};
    Solution slt;
    slt.moveZeroes(nums);
    print_vec1d_arr(nums);
    return 0;
}
