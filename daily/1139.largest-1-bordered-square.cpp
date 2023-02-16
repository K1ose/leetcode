/* 1139. 最大的以 1 为边界的正方形
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。



示例 1：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：

输入：grid = [[1,1,0,0]]
输出：1


提示：

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为 0 或 1 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        /* TODO:to review */
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m + 1, vector<int>(n + 1));
        vector<vector<int>> up(m + 1, vector<int>(n + 1));
        int maxBorder = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (grid[i - 1][j - 1] == 1)
                {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int border = min(left[i][j], up[i][j]);
                    while (left[i - border + 1][j] < border || up[i][j - border + 1] < border)
                    {
                        border--;
                    }
                    maxBorder = max(maxBorder, border);
                }
            }
        }
        return maxBorder * maxBorder;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
