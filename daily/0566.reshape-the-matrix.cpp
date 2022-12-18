/* 566. 重塑矩阵
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。

给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。

如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。



示例 1：


输入：mat = [[1,2],[3,4]], r = 1, c = 4
输出：[[1,2,3,4]]
示例 2：


输入：mat = [[1,2],[3,4]], r = 2, c = 4
输出：[[1,2],[3,4]]


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* 假设有m*n个元素，存放在一个y列的矩阵matrix里，那么对应的下标为：
        for(int i = 0; i < m*n; i++){
            int new_row = i/y;  // 得到行号
            int new_col = i%y;  // 得到列号
            int row = i/n;
            int col = i%n;
        }
     */
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int row = mat.size(), col = mat[0].size();
        if (r * c != row * col)
            return mat;

        vector<vector<int>> new_matrix(r, vector<int>(c));
        for (int i = 0; i < row * col; i++)
        {
            new_matrix[i / c][i % c] = mat[i / col][i % col];
        }
        return new_matrix;
    }
};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int r, c;
    cin >> r >> c;
    Solution slt;
    mat = slt.matrixReshape(mat, r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
