/* 1779. 找到最近的有相同 X 或 Y 坐标的点
给你两个整数 x 和 y ，表示你在一个笛卡尔坐标系下的 (x, y) 处。同时，在同一个坐标系下给你一个数组 points ，其中 points[i] = [ai, bi] 表示在 (ai, bi) 处有一个点。当一个点与你所在的位置有相同的 x 坐标或者相同的 y 坐标时，我们称这个点是 有效的 。

请返回距离你当前位置 曼哈顿距离 最近的 有效 点的下标（下标从 0 开始）。如果有多个最近的有效点，请返回下标 最小 的一个。如果没有有效点，请返回 -1 。

两个点 (x1, y1) 和 (x2, y2) 之间的 曼哈顿距离 为 abs(x1 - x2) + abs(y1 - y2) 。



示例 1：

输入：x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
输出：2
解释：所有点中，[3,1]，[2,4] 和 [4,4] 是有效点。有效点中，[2,4] 和 [4,4] 距离你当前位置的曼哈顿距离最小，都为 1 。[2,4] 的下标最小，所以返回 2 。
示例 2：

输入：x = 3, y = 4, points = [[3,4]]
输出：0
提示：答案可以与你当前所在位置坐标相同。
示例 3：

输入：x = 3, y = 4, points = [[2,3]]
输出：-1
解释：没有 有效点。


提示：

1 <= points.length <= 104
points[i].length == 2
1 <= x, y, ai, bi <= 104 */

#include <iostream>
#include <vector>
using namespace std;
#define INF 0x7fffffff
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        /* 模拟 */
        int manhattan_distance = INF;
        int ans;
        int size = points.size();
        for (int i = 0; i < size; i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int new_m_dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (manhattan_distance > new_m_dis)
                {
                    ans = i;
                    manhattan_distance = new_m_dis;
                }
            }
        }
        if (manhattan_distance == INF)
            return -1;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> points[i][j];

    Solution slt;
    cout << slt.nearestValidPoint(x, y, points) << endl;
    return 0;
}