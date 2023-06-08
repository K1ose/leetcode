/* 1796. 字符串中第二大的数字
给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。

混合字符串 由小写英文字母和数字组成。



示例 1：

输入：s = "dfa12321afd"
输出：2
解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
示例 2：

输入：s = "abc1111"
输出：-1
解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。


提示：

1 <= s.length <= 500
s 只包含小写英文字母和（或）数字。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
class Solution
{
public:
    /* 什么奇怪的做法，直接用两个变量记录最大值和第二大值就好了 */
    int secondHighest(string s)
    {
        int len = s.size();

        int nums[10] = {0};
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                nums[s[i] - 48] += 1;
            }
        }
        // print_arr(nums, 10);

        int idx = 0;
        for (int i = 9; i >= 0; i--)
        {
            if (nums[i] == 0)
                continue;
            else
                idx++;
            if (idx == 2)
                return i;
        }
        return -1;
    }

    int second_highest(string s)
    {
        int first = -1, second = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                if (s[i] - 48 > first)
                {
                    second = first;
                    first = s[i] - 48;
                }
                else if (s[i] - 48 < first && s[i] - 48 > second)
                    second = s[i] - 48;
            }
        }
        return second;
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    Solution slt;
    cout << slt.second_highest(str) << endl;
    return 0;
}
