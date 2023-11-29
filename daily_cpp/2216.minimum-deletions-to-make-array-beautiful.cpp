/* 2216. 美化数组的最少删除数
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的整数数组 nums ，如果满足下述条件，则认为数组 nums 是一个 美丽数组 ：

nums.length 为偶数
对所有满足 i % 2 == 0 的下标 i ，nums[i] != nums[i + 1] 均成立
注意，空数组同样认为是美丽数组。

你可以从 nums 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 不变 。

返回使 nums 变为美丽数组所需删除的 最少 元素数目。



示例 1：

输入：nums = [1,1,2,3,5]
输出：1
解释：可以删除 nums[0] 或 nums[1] ，这样得到的 nums = [1,2,3,5] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 1 个元素。
示例 2：

输入：nums = [1,1,2,2,3,3]
输出：2
解释：可以删除 nums[0] 和 nums[5] ，这样得到的 nums = [1,2,2,3] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 2 个元素。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 105 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /*  要去除 i % 2 == 0 && nums[i] == nums[i+1] 的坏元素，可以通过删除其他元素来改变坏元素的下表，从而使之变为好元素。
        假设下表最小的坏元素下标为j，在进行其他元素删除时，会出现以下情况：
        当删除元素下标 i ：
        1. i > j+1 时，坏元素并不会移动，且nums[j+1]==nums[j]，nums[j]仍然是坏元素
        2. i < j 时，存在以下情况：
            1）前移时坏元素对应下标仍然是坏元素，例如 {0,2,1,1,1}，其中 下标为 2 的元素是坏元素。在删除0或者2后，{x,1,1,1} 的数组中，下标为 2 的元素为坏元素。因为 j % 2 == 0 且 nums[j] = nums[j+1] = 1
            2）前移时出现新的坏元素，例如 {0,1,1,1}，其中 下标为 2 的元素是坏元素。在删除0后，{1,1,1} 的数组中，下标为 0 的元素为坏元素。
        3. i = j 或 i = j+1 时，我们会得到两个一样的数组，可以理解为后面的元素前移，可能会出现 2. 中的 1）类情况，例如 {0,2,1,1,1,1}，在删除下标为 2 的坏元素后，得到 {0,2,1,1,1}，下标为 2 的元素仍然为坏元素。但不会出现 2. 中的 2）类情况，因为删除 j 或 j+1 处的元素，不会改变坏元素的前序元素。

        因此，只需要检测最小下标坏元素的位置，对该位置的坏元素进行删除操作，删除后后序元素的下标奇偶性都发生了变化。所以我们可以用一个flag来标记，当删除操作发生后，下一个元素继承了当前元素的奇偶性，奇偶性不反转，flag不变，如果删除操作未发生，下一个元素与当前元素奇偶性不一致，则奇偶性反转，flag = !flag。然后检测当前位置是否为坏元素，并以此步骤进行遍历，最后对数组长度做检测，如果是奇数，则删除最后一个元素 */
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int del_cnt = 0;
        bool flag = true;
        for (int i = 0; i + 1 < n; i++)
        {
            if (flag && nums[i] == nums[i + 1])
            {
                del_cnt++;
            }
            else
            {
                flag = !flag;
            }
        }
        if ((n - del_cnt) % 2 != 0)
        {
            del_cnt++;
        }
        return del_cnt;
    }

    /*
    int n = nums.size(), k = 0;
    for(int i = 0; i < n - 1; i ++)
        k += (i - k) % 2 == 0 && nums[i] == nums[i + 1];

    return k + (n - k) % 2; */
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 1, 1};
    Solution slt;
    cout << slt.minDeletion(nums) << endl;
    return 0;
}