/* 2342. 数位和相等数对的最大和
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。

请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。



示例 1：

输入：nums = [18,43,36,13,7]
输出：54
解释：满足条件的数对 (i, j) 为：
- (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
- (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
所以可以获得的最大和是 54 。
示例 2：

输入：nums = [10,12,19,14]
输出：-1
解释：不存在满足条件的数对，返回 -1 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int getDigitSum(int num)
    {
        /*
        int sum = 0;

        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
         */
        int sum = 0;
        string num_str = to_string(num);
        for (auto c : num_str)
        {
            sum += c - '0';
        }
        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        vector<int> digit_sum;
        unordered_map<int, int> umap;

        sort(nums.begin(), nums.end());

        int ans = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int cur_sum = getDigitSum(nums[i]);
            if (umap.count(cur_sum))
            {
                ans = max(ans, umap[cur_sum] + nums[i]);
            }
            umap[cur_sum] = max(umap[cur_sum], nums[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364, 300, 191, 438, 467, 183};
    Solution slt;
    cout << slt.maximumSum(nums) << endl;
    return 0;
}
