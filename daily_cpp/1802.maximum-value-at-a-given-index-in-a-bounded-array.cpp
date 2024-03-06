/* 1802. 有界数组中指定下标处的最大值
给你三个正整数 n、index 和 maxSum 。你需要构造一个同时满足下述所有条件的数组 nums（下标 从 0 开始 计数）：

nums.length == n
nums[i] 是 正整数 ，其中 0 <= i < n
abs(nums[i] - nums[i+1]) <= 1 ，其中 0 <= i < n-1
nums 中所有元素之和不超过 maxSum
nums[index] 的值被 最大化
返回你所构造的数组中的 nums[index] 。

注意：abs(x) 等于 x 的前提是 x >= 0 ；否则，abs(x) 等于 -x 。



示例 1：

输入：n = 4, index = 2,  maxSum = 6
输出：2
解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
示例 2：

输入：n = 6, index = 1,  maxSum = 10
输出：3


提示：

1 <= n <= maxSum <= 109
0 <= index < n */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxValue_math(int n, int index, int maxSum)
    {
        double left = index;
        double right = n - index - 1;
        if (left > right)
        {
            double temp = left;
            left = right;
            right = temp;
        }

        double upper = ((double)(left + 1) * (left + 1) - 3 * (left + 1)) / 2 + left + 1 + (left + 1) + ((left + 1) * (left + 1) - 3 * (left + 1)) / 2 + right + 1;
        if (upper >= maxSum)
        {
            double a = 1;
            double b = -2;
            double c = left + right + 2 - maxSum;
            return (int)floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
        }

        upper = ((double)2 * (right + 1) - left - 1) * left / 2 + (right + 1) + ((right + 1) * (right + 1) - 3 * (right + 1)) / 2 + right + 1;
        if (upper >= maxSum)
        {
            double a = 1.0 / 2;
            double b = left + 1 - 3.0 / 2;
            double c = right + 1 + (-left - 1) * left / 2 - maxSum;
            return (int)floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
        }
        else
        {
            double a = left + right + 1;
            ;
            double b = (-left * left - left - right * right - right) / 2 - maxSum;
            return (int)floor(-b / a);
        }
    }

    int maxValue(int n, int index, int maxSum)
    {
        int left = 1, right = maxSum;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (valid(mid, n, index, maxSum))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    bool valid(int mid, int n, int index, int maxSum)
    {
        int left = index;
        int right = n - index - 1;
        return mid + cal(mid, left) + cal(mid, right) <= maxSum;
    }

    long cal(int big, int length)
    {
        if (length + 1 < big)
        {
            int small = big - length;
            return (long)(big - 1 + small) * length / 2;
        }
        else
        {
            int ones = length - (big - 1);
            return (long)big * (big - 1) / 2 + ones;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, idx, maxSum;
    cin >> n >> idx >> maxSum;
    Solution slt;
    cout << slt.maxValue(n, idx, maxSum) << endl;
    return 0;
}
