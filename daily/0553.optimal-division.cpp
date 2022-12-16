/*
2022-2-27
给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。

但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。

示例：

输入: [1000,100,10,2]
输出: "1000/(100/10/2)"
解释:
1000/(100/10/2) = 1000/((100/10)/2) = 200
但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

其他用例:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
说明:

输入数组的长度在 [1, 10] 之间。
数组中每个元素的大小都在 [2, 1000] 之间。
每个测试用例只有一个最优除法解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/optimal-division
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 虽然看起来很复杂，实际上根据除法的特性，不需要用到回溯来求解，因为数总是越除越小，而第一个数不可能改变其被除数的身份，所以当后面的数进行除法后得到的数即除数最小时，得到的商即为最大。因此只需要将除了第一个数以外的数用括号括起来进行除法即可得到结果
class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        string ans;
        int n = nums.size();
        if (n == 1)
        {
            ans = to_string(nums[0]);
            return ans;
        }
        if (n == 2)
        {
            ans = to_string(nums[0]) + '/' + to_string(nums[1]);
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 1)
                ans = ans + '(' + to_string(nums[i]) + '/';
            else if (i == n - 1)
                ans = ans + to_string(nums[i]) + ')';
            else
            {
                ans = ans + to_string(nums[i]) + '/';
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {100, 7, 4, 2};
    string ans;
    Solution test;
    ans = test.optimalDivision(nums);
    cout << ans << endl;
}