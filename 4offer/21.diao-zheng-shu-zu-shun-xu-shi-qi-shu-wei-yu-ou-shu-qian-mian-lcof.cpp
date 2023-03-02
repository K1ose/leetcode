/* 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。



示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。



提示：

    0 <= nums.length <= 50000
    0 <= nums[i] <= 10000

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        /* 双指针，存放奇数的指针指向数组最前方，存放偶数的指针指向数组最后，两个指针向中间靠拢 */
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> res(n);
        for (int &num : nums)
        {
            if (num % 2 == 0)
            {
                res[right] = num;
                right--;
            }
            else
            {
                res[left] = num;
                left++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
