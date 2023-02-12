/* 1138. 字母板上的路径
我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。



我们可以按下面的指令规则行动：

如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
（注意，字母板上只存在有字母的位置。）

返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。



示例 1：

输入：target = "leet"
输出："DDR!UURRR!!DDD!"
示例 2：

输入：target = "code"
输出："RR!DDRR!UUL!R!"


提示：

1 <= target.length <= 100
target 仅含有小写英文字母。 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        /* 当前坐标 */
        int cur_x = 0, cur_y = 0;
        string ans;
        for (char c : target)
        {
            int target_x = (c - 'a') / 5; /* 当前字母所处的行 */
            int target_y = (c - 'a') % 5; /* 当前字母所处的列 */

            if (target_x < cur_x)
            {
                ans.append(cur_x - target_x, 'U');
            }
            if (target_y < cur_y)
            {
                ans.append(cur_y - target_y, 'L');
            }
            if (target_x > cur_x)
            {
                ans.append(target_x - cur_x, 'D');
            }
            if (target_y > cur_y)
            {
                ans.append(target_y - cur_y, 'R');
            }
            ans.push_back('!');
            cur_x = target_x;
            cur_y = target_y;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string target;
    cin >> target;
    Solution slt;
    cout << slt.alphabetBoardPath(target) << endl;
    return 0;
}
