/* 1129. 颜色交替的最短路径
在一个有向图中，节点分别标记为 0, 1, ..., n-1。图中每条边为红色或者蓝色，且存在自环或平行边。

red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。

返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。



示例 1：

输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
输出：[0,1,-1]
示例 2：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
输出：[0,1,-1]
示例 3：

输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
输出：[0,-1,-1]
示例 4：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
输出：[0,1,2]
示例 5：

输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
输出：[0,1,1]


提示：

1 <= n <= 100
red_edges.length <= 400
blue_edges.length <= 400
red_edges[i].length == blue_edges[i].length == 2
0 <= red_edges[i][j], blue_edges[i][j] < n */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        /* bfs */
        /*
        next[0]: 存放路径最终到节点 x 的有向边为红色
        next[1]: 存放路径最终到节点 x 的有向边为蓝色 */
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));

        for (auto edge : redEdges)
        {
            /* 源节点到目的节点为红边 */
            next[0][edge[0]].push_back(edge[1]);
        }
        for (auto edge : blueEdges)
        {
            /* 源节点到目的节点为蓝边 */
            next[1][edge[0]].push_back(edge[1]);
        }

        /* 两种颜色类型的最短路径，初始化为最大值 */
        vector<vector<int>> distance(2, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        /* x为1时，0节点出发的最短距离都为0 */
        distance[0][0] = 0, distance[1][0] = 0;

        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty())
        {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : next[1 - t][x])
            {
                if (distance[1 - t][y] != INT_MAX)
                {
                    continue;
                }
                distance[1 - t][y] = distance[t][x] + 1;
                q.push({y, 1 - t});
            }
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            answer[i] = min(distance[0][i], distance[1][i]);
            if (answer[i] == INT_MAX)
            {
                answer[i] = -1;
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
