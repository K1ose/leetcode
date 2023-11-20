/* 26. 删除有序数组中的重复项
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。



示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。


提示：

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 升序 排列
 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int removeDuplicates_stupid(vector<int> &nums)
    {
        int nSize = nums.size();
        if (nSize == 0)
            return 0;

        unordered_map<int, int> cnt;
        for (int i = 0, j = 0; i < nSize; i++)
        {
            if (!cnt.count(nums[i]))
            {
                nums[j] = nums[i];
                j++;
            }
            cnt[nums[i]]++;
        }
        return cnt.size();
    }

    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 1;
        }

        int p = 0, q = 1;
        while (p + 1 < n && q < n)
        {
            if (nums[p] != nums[q])
            {
                nums[p + 1] = nums[q];
                p++;
            }
            else
            {
                q++;
            }
        }
        return p + 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1};
    Solution slt;
    cout << slt.removeDuplicates(nums) << endl;
    return 0;
}
