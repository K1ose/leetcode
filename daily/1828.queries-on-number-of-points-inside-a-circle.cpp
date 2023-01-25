/* 1828. 统计一个圆中点的数目
给你一个数组 points ，其中 points[i] = [xi, yi] ，表示第 i 个点在二维平面上的坐标。多个点可能会有 相同 的坐标。

同时给你一个数组 queries ，其中 queries[j] = [xj, yj, rj] ，表示一个圆心在 (xj, yj) 且半径为 rj 的圆。

对于每一个查询 queries[j] ，计算在第 j 个圆 内 点的数目。如果一个点在圆的 边界上 ，我们同样认为它在圆 内 。

请你返回一个数组 answer ，其中 answer[j]是第 j 个查询的答案。



示例 1：


输入：points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
输出：[3,2,2]
解释：所有的点和圆如上图所示。
queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆。
示例 2：


输入：points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
输出：[2,3,2,4]
解释：所有的点和圆如上图所示。
queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆，queries[3] 是紫色的圆。


提示：

1 <= points.length <= 500
points[i].length == 2
0 <= x​​​​​​i, y​​​​​​i <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
所有的坐标都是整数。 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int circle_x = queries[i][0], circle_y = queries[i][1];
            double radius = queries[i][2];
            for (int j = 0; j < points.size(); j++)
            {
                int point_x = points[j][0], point_y = points[j][1];
                double dis = sqrt((point_x - circle_x) * (point_x - circle_x) + (point_y - circle_y) * (point_y - circle_y));
                if (dis <= radius)
                {
                    count++;
                }
            }
            ans.emplace_back(count);
            count = 0;
        }
        return ans;
    }
};

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int m, n;

    cin >> m;
    vector<vector<int>> points(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> points[i][j];
        }
    }

    cin >> n;
    vector<vector<int>> queries(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }
    }

    Solution slt;
    vector<int> ans;
    ans = slt.countPoints(points, queries);
    print_arr(ans);
    return 0;
}
