/* 169. 多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2


提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        /* Boyer-Moore 投票算法 */
        /* 如果我们把多数记为+1，把其他数记为−1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出多数比其他数多 */
        /*
            - 我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
            - 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：
                - 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
                - 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
            - 在遍历完成candidate 即为整个数组的众数。
        */
        /*
            - 投票算法证明：
                - 如果候选人不是 maj 则 maj 会和其他非候选人一起反对 当前候选人， 所以候选人一定会下台(maj==0时发生换届选举)
                - 如果候选人是 maj ， 则 maj 会支持自己，其他候选人会反对，同样因为maj 票数超过一半，所以maj 一定会成功当选
             */
        int candidate;
        int cnt = 0;
        for (auto num : nums)
        {
            if (cnt == 0)
            {
                candidate = num;
            }
            if (num != candidate)
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
        }
        return candidate;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, 3};
    Solution slt;
    cout << slt.majorityElement(nums) << endl;
    return 0;
}
