/* 2642. 设计可以求最短路径的图类

给你一个有 n 个节点的 有向带权 图，节点编号为 0 到 n - 1 。图中的初始边用数组 edges 表示，其中 edges[i] = [fromi, toi, edgeCosti] 表示从 fromi 到 toi 有一条代价为 edgeCosti 的边。

请你实现一个 Graph 类：

    Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
    addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。数据保证添加这条边之前对应的两个节点之间没有有向边。
    int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。



示例 1：

输入：
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
输出：
[null, 6, -1, null, 6]

解释：
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // 返回 6 。从 3 到 2 的最短路径如第一幅图所示：3 -> 0 -> 1 -> 2 ，总代价为 3 + 2 + 1 = 6 。
g.shortestPath(0, 3); // 返回 -1 。没有从 0 到 3 的路径。
g.addEdge([1, 3, 4]); // 添加一条节点 1 到节点 3 的边，得到第二幅图。
g.shortestPath(0, 3); // 返回 6 。从 0 到 3 的最短路径为 0 -> 1 -> 3 ，总代价为 2 + 4 = 6 。



提示：

    1 <= n <= 100
    0 <= edges.length <= n * (n - 1)
    edges[i].length == edge.length == 3
    0 <= fromi, toi, from, to, node1, node2 <= n - 1
    1 <= edgeCosti, edgeCost <= 106
    图中任何时候都不会有重边和自环。
    调用 addEdge 至多 100 次。
    调用 shortestPath 至多 100 次。

 */
#include "../tools/program_head.h"
#include "../tools/struct.h"
#include "../tools/display.h"
using namespace std;

class Graph
{
public:
    vector<vector<int>> g; /* g[i][j]表示从i到j的cost */

    /* 初始化 */
    Graph(int n, vector<vector<int>> &edges)
    {
        // 邻接矩阵（初始化为无穷大，表示 i 到 j 没有边）
        g = vector<vector<int>>(n, vector<int>(n, INT32_MAX / 2));
        for (auto e : edges)
        {
            g[e[0]][e[1]] = e[2];
        }
    }

    /* 添加一条边 */
    void addEdge(vector<int> edge)
    {
        g[edge[0]][edge[1]] = edge[2];
    }

    /* 返回从node1到node2的最小cost，使用朴素Dijkstra算法 */
    int shortestPath(int node1, int node2)
    {
        int size = g.size();
        vector<int> dis(size, INT32_MAX), vis(size);
        dis[node1] = 0; /* 起始的cost为0 */

        for (;;)
        {
            // 找到当前最短路，去更新它的邻居的最短路
            // 根据数学归纳法，dis[x] 一定是最短路长度
            int x = -1;
            for (int i = 0; i < size; i++)
            {
                if (!vis[i] && (x < 0 || dis[i] < dis[x]))
                {
                    x = i;
                }
            }
            if (x < 0 || dis[x] == INT32_MAX / 2) // 所有从 start 能到达的点都被更新了
                return -1;
            if (x == node2) // 找到终点，提前退出
                return dis[x];
            vis[x] = true; // 标记，在后续的循环中无需反复更新 x 到其余点的最短路长度
            for (int y = 0; y < size; ++y)
                dis[y] = min(dis[y], dis[x] + g[x][y]); // 更新最短路长度
        }
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main(int argc, char const *argv[])
{

    return 0;
}
