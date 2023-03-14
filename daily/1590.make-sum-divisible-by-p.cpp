/* 1590. 使数组和能被 P 整除

给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。



示例 1：

输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。

示例 2：

输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。

示例 3：

输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。

示例  4：

输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。

示例 5：

输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0



提示：

    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    1 <= p <= 109

 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    /* 题目说明的是子数组，用双指针的话，需要元素满足前缀和数组s[i]满足单调性：即，s[i]mod p 单调 */
    /* 两个数 x 和 y，如果 (x−y) mod p=0，则称 x 与 y 对模 p 同余，记作 x≡y(modp) */
    /* 通过前缀和，问题转换成：在前缀和数组上找到两个数 s[left] 和 s[right]，满足 right−left 最小且 s[right]−s[left]≡x(modp)，移项得 s[right]−x≡s[left](modp) */
    /* 遍历 s 的同时，用哈希表 last 记录 s[i] mod p 最近一次出现的下标，如果 last 中包含 (s[i] mod p−x mod p+p) mod p，设其对应的下标为 j，那么 [j,i) 是一个符合题目要求的子数组。枚举所有 i，计算符合要求的子数组长度的最小值，就是答案。如果没有符合要求的子数组，则返回 −1。
     */
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size(), res = n;
        int s[n + 1]; /* 前缀和 */
        s[0] = 0;
        for (int i = 0; i < n; i++)
        {
            s[i + 1] = (s[i] + nums[i]) % p;
        }
        int x = s[n]; /* x 为所有元素前缀和 */
        if (x % p == 0)
        {
            /* 如果满足条件 */
            return 0;
        }

        unordered_map<int, int> last;
        for (int i = 0; i <= n; i++)
        {
            last[s[i]] = i; /* 记录每个前缀和以及它们对应的下标 */
            auto it = last.find((s[i] - x + p) % p);
            if (it != last.end())
            {
                res = min(res, i - it->second);
            }
        }
        return res < n ? res : -1;
    }
};
