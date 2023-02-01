/* 1496. 判断路径是否相交
给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。

你从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。

如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 true ；否则，返回 false 。



示例 1：



输入：path = "NES"
输出：false
解释：该路径没有在任何位置相交。
示例 2：



输入：path = "NESWW"
输出：true
解释：该路径经过原点两次。


提示：

1 <= path.length <= 104
path[i] 为 'N'、'S'、'E' 或 'W' */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        /* TODO first */
        int vertical = 0, horizontal = 0;
        for (char c : path)
        {
            switch (c)
            {
            case 'S':
                /* code */
                vertical++;
                break;
            case 'N':
                vertical--;
                break;
            case 'W':
                horizontal++;
                break;
            case 'E':
                horizontal--;
                break;
            default:
                break;
            }

            if (vertical == 0 && horizontal == 0)
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string path;
    cin >> path;
    Solution slt;
    cout << slt.isPathCrossing(path) << endl;
    return 0;
}
