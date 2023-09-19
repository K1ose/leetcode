/* 88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。



示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
示例 3：

输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。


提示：

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                ans.push_back(nums2[j]);
                j++;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while (i < m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        nums1 = ans;
        // for (int k = 0; k < m + n; k++)
        //     nums1[k] = ans[k];
    }

    /* less space to used */
    void merge_less_space(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = nums1.size() - 1;
        m--, n--;
        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])
            {
                swap(nums1[len--], nums1[m--]);
            }
            swap(nums1[len--], nums2[n--]);
        }
    }
};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m;
    cin >> n;

    vector<int> nums1(m + n);
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    Solution slt;
    slt.merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
