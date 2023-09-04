/* 228. 汇总区间
简单
341
相关企业
给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b


示例 1：

输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
示例 2：

输入：nums = [0,2,3,4,6,8,9]
输出：["0","2->4","6","8->9"]
解释：区间范围是：
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


提示：

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
nums 中的所有值都 互不相同
nums 按升序排列 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int i = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int pre = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
            {
                i++;
            }
            string ans_temp;
            if (pre == nums[i])
            {
                ans_temp = to_string(pre);
            }
            else
            {
                ans_temp = to_string(pre) + "->" + to_string(nums[i]);
            }
            ans.push_back(ans_temp);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 3, 5, 7, 9};
    Solution slt;
    print_vec1d_arr(slt.summaryRanges(nums));
    return 0;
}
