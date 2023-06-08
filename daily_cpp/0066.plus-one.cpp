/* 66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。



示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]


提示：

1 <= digits.length <= 100
0 <= digits[i] <= 9
 */

#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int dSize = digits.size();
        if (digits[dSize - 1] != 9)
        {
            digits[dSize - 1]++;
            return digits;
        }
        int i = dSize - 1;
        while (i >= 0 && digits[i] == 9)
        {
            digits[i] = 0;
            i--;
        }
        if (i == -1)
        {
            digits.insert(digits.begin(), 1);
        }
        else
        {
            digits[i]++;
        }
        return digits;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    Solution slt;
    slt.plusOne(digits);

    return 0;
}
