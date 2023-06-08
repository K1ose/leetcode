/* 2373. 矩阵中的局部最大值

给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

    maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。

换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。

返回生成的矩阵。



示例 1：

输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
输出：[[9,9],[8,6]]
解释：原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。

示例 2：

输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
输出：[[2,2,2],[2,2,2],[2,2,2]]
解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。



提示：

    n == grid.length == grid[i].length
    3 <= n <= 100
    1 <= grid[i][j] <= 100

 */
#include <iostream>
#include <vector>
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /* 遍历 */
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ret(n - 2, vector<int>(n - 2, 0));
        /* 对于 ret 矩阵 */
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                /* 遍历当前的3x3矩阵 */
                for (int m = i; m < i + 3; m++)
                {
                    for (int n = j; n < j + 3; n++)
                    {
                        /* 保存最大值 */
                        ret[i][j] = max(ret[i][j], grid[m][n]);
                    }
                }
            }
        }
        return ret;
    }

    /*
   假设grid矩阵行数为m,列数为n，求行数为h，列数为w的矩阵内的最大值，并将其保存在行数为m-h+1，列数为n-w+1的矩阵中，返回矩阵
   解法：二维单调队列
    */
    vector<vector<int>> largestLocal_hw(vector<vector<int>> &grid, int h, int w)
    {
        /* m 为 grid 的行数， n 为 grid 的列数 */
        int m = grid.size(), n = grid[0].size();

        /* 遍历每行 */
        for (int i = 0; i < m; i++)
        {
            /* 遍历每一个滑动窗口 */
            for (int j = 0; j < n - w + 1; j++)
            {
                int k, max_e = 0;
                /* 找出每一个滑动窗口的最大值，并存放在该窗口的第一个位置 */
                for (k = j; k < j + w; k++)
                {
                    max_e = max(max_e, grid[i][k]);
                }
                grid[i][j] = max_e;
            }
        }

        /* 返回矩阵 */
        vector<vector<int>> ret(m - h + 1, vector<int>(n - w + 1, 0));

        /* 遍历每一列 */
        for (int j = 0; j < n - w + 1; j++)
        {
            /* 遍历每一列的滑动窗口 */
            for (int i = 0; i < m - h + 1; i++)
            {
                int k, max_e = 0;
                /* 获取窗口内最大值，存放到返回矩阵的对应位置 */
                for (k = i; k < i + h; k++)
                {
                    max_e = max(max_e, grid[k][j]);
                }
                ret[i][j] = max_e;
            }
        }
        return ret;
    }

    /* 二维单调队列的对应题目解法 */
    vector<vector<int>> largestLocal_hw(vector<vector<int>> &grid)
    {
        int h = 3, w = 3;
        /* m 为 grid 的行数， n 为 grid 的列数 */
        int m = grid.size(), n = grid[0].size();

        /* 遍历每行 */
        for (int i = 0; i < m; i++)
        {
            /* 遍历每一个滑动窗口 */
            for (int j = 0; j < n - w + 1; j++)
            {
                int k, max_e = 0;
                /* 找出每一个滑动窗口的最大值，并存放在该窗口的第一个位置 */
                for (k = j; k < j + w; k++)
                {
                    max_e = max(max_e, grid[i][k]);
                }
                grid[i][j] = max_e;
            }
        }

        /* 返回矩阵 */
        vector<vector<int>> ret(m - h + 1, vector<int>(n - w + 1, 0));

        /* 遍历每一列 */
        for (int j = 0; j < n - w + 1; j++)
        {
            /* 遍历每一列的滑动窗口 */
            for (int i = 0; i < m - h + 1; i++)
            {
                int k, max_e = 0;
                /* 获取窗口内最大值，存放到返回矩阵的对应位置 */
                for (k = i; k < i + h; k++)
                {
                    max_e = max(max_e, grid[k][j]);
                }
                ret[i][j] = max_e;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2},
    };
    Solution slt;
    slt.largestLocal_hw(grid, 3, 3);
    return 0;
}
