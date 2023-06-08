/* 2032. 至少在两个数组中出现的值
给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。


示例 1：

输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
输出：[3,2]
解释：至少在两个数组中出现的所有值为：
- 3 ，在全部三个数组中都出现过。
- 2 ，在数组 nums1 和 nums2 中出现过。
示例 2：

输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
输出：[2,3,1]
解释：至少在两个数组中出现的所有值为：
- 2 ，在数组 nums2 和 nums3 中出现过。
- 3 ，在数组 nums1 和 nums2 中出现过。
- 1 ，在数组 nums1 和 nums3 中出现过。
示例 3：

输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
输出：[]
解释：不存在至少在两个数组中出现的值。


提示：

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        vector<int> ans;
        unordered_map<int, int> count;
        for (int x : nums1)
        {
            count[x] = 1; // 0001
        }
        for (int x : nums2)
        {
            count[x] |= 2; // 0010
        }

        for (int x : nums3)
        {
            count[x] |= 4; // 0100
        }

        /* 0011 0101 0110 0111 */
        for (auto [k, v] : count)
        {
            if (v == 3 || v == 5 || v == 6 || v == 7)
                /* if(v & v-1) */
                ans.emplace_back(k);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> nums1(n1), nums2(n2), nums3(n3);

    for (int i = 0; i < n1; i++)
        cin >> nums1[i];
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];
    for (int i = 0; i < n3; i++)
        cin >> nums3[i];

    vector<int> ans;
    Solution slt;
    ans = slt.twoOutOfThree(nums1, nums2, nums3);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
