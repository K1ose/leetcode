/* 189. 轮转数组
中等
相关标签
相关企业
提示
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。



示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]


提示：

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


进阶：

尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？ */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    void reverse_arr(vector<int> &nums, int start, int end)
    {
        int n = end - start + 1;
        int mid = n / 2;
        for (int i = 0; i < mid; i++)
        {
            cout << start + i << " and " << end - i << endl;
            int temp = nums[start + i];

            nums[start + i] = nums[end - i];
            nums[end - i] = temp;
        }
        print_vec1d_arr(nums);
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse_arr(nums, n - k, n - 1);
        reverse_arr(nums, 0, n - k - 1);
        reverse_arr(nums, 0, n - 1);

        /*
        reverse_arr(nums, 0, n - 1);
        reverse_arr(nums, 0, k - 1);
        reverse_arr(nums, k, n - 1);
         */
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution slt;
    slt.rotate(nums, k);
    return 0;
}
