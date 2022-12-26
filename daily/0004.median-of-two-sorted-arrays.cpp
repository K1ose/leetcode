/* 4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。



示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5




提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int arr[2020] = {0};
        int i = 0, j = 0, k = -1;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (i < len1 && j < len2)
        {
            if (nums1[i] < nums2[j])
            {
                arr[++k] = nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                arr[++k] = nums2[j];
                j++;
            }
            else
            {
                arr[++k] = nums1[i];
                arr[++k] = nums2[j];
                i++;
                j++;
            }
        }
        while (i < len1 && nums1[i])
        {
            arr[++k] = nums1[i];
            i++;
        }
        while (j < len2 && nums2[j])
        {
            arr[++k] = nums2[j];
            j++;
        }
        if (k % 2 != 0)
        {
            return (double)(arr[(k + 1) / 2] + arr[k / 2]) / 2;
        }
        else
        {
            return (double)arr[k / 2];
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
