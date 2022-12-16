/* 350. 两个数组的交集 II
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。



示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]


提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


进阶：

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？ */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;

        for (auto x : nums1) /* 统计nums1中各元素出现的次数 */
            map[x]++;

        vector<int> ans;
        for (auto y : nums2)
        {
            if (map.count(y)) /* 如果nums2中有和nums1相同的元素 */
            {
                ans.push_back(y); /* 添加到最终的数组中 */
                map[y]--;         /* 相同元素数量-1 */
                if (map[y] == 0)  /* 如果抵消了，则删除在map中的该元素，保证输出的重复元素是较小的那个 */
                    map.erase(y);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    for (int i = 0; i < m; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    Solution slt;
    vector<int> ans;
    ans = slt.intersect(nums1, nums2);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
