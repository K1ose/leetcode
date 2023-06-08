/* 1004. 最大连续1的个数 III

给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。



示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。



提示：

    1 <= nums.length <= 105
    nums[i] 不是 0 就是 1
    0 <= k <= nums.length

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, cnt = 0;
        int lsum = 0, rsum = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++)
        {
            /* 如果nums[right]为1,则rsum不变，如果nums[right]为0,则rsum++ */
            rsum += 1 - nums[right];
            /* 如果用完了k次反转机会，则判断nums[left]是否为0,如果是则lsum++，如果不是则不变，让left指针移动，来返还一次反转机会 */
            while (lsum < rsum - k)
            {
                lsum += 1 - nums[left];
                left++;
            }
            cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    Solution slt;
    cout << slt.longestOnes(nums, k) << endl;
    return 0;
}
