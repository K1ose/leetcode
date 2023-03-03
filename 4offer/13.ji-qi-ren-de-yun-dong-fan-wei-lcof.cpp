/* 面试题13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？



示例 1：

输入：m = 2, n = 3, k = 1
输出：3

示例 2：

输入：m = 3, n = 1, k = 0
输出：1

提示：

    1 <= n,m <= 100
    0 <= k <= 20

 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    /// @brief 计算数位和
    /// @param num - 被计算的数
    /// @return - 返回数位和
    int digit_sum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    /* 回溯法 */
    /// @brief 递推移动
    /// @param m - m行
    /// @param n - n列
    /// @param visited - 访问二维数组
    /// @param i - 当前行
    /// @param j - 当前列
    /// @param k - 限制
    /// @param count - 计数
    /// @return false 表示当前位置不符合条件限制， true 表示正常退出
    bool move(int m, int n, vector<vector<int>> visited, int i, int j, int k, int &count)
    {
        /* 不符合条件则返回false */
        if (digit_sum(i) + digit_sum(j) > k)
        {
            return false;
        }
        visited[i][j] = true;
        /* 记录当前位置 */
        count++;

        /* 方向向量 */
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        /* 查找四个方向的下一个位置 */
        for (auto direction : directions)
        {
            int new_i = i + direction.first, new_j = j + direction.second;
            if (new_i < m && new_i >= 0 && new_j < n && new_j >= 0)
            {
                if (!visited[new_i][new_j])
                {
                    move(m, n, visited, new_i, new_j, k, count);
                }
            }
        }
        return true;
    }

    /// @brief
    /// @param m - m 行，1 <= m <= 100
    /// @param n - n 列，1 <= n <= 100
    /// @param k - m位数+n位数和 < k
    /// @return - 机器人能够到达的格子数
    int movingCount(int m, int n, int k)
    {
        if (!k)
        {
            return 1;
        }
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        move(m, n, visited, 0, 0, k, count);
        return count;
    }

    /* 递推 */
    int movingCount(int m, int n, int k)
    {
        if (!k)
            return 1;
        queue<pair<int, int>> Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty())
        {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; ++i)
            {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || digit_sum(tx) + digit_sum(ty) > k)
                    continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
    /* BFS */
    int movingCount(int m, int n, int k)
    {
        if (!k)
            return 1;
        queue<pair<int, int>> Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty())
        {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; ++i)
            {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || digit_sum(tx) + digit_sum(ty) > k)
                    continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int m, n, k;
    cin >> m >> n >> k;
    Solution slt;
    cout << slt.movingCount(m, n, k) << endl;
    return 0;
}
