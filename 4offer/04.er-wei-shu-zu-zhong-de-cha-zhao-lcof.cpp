/* 剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。



示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。



限制：

0 <= n <= 1000

0 <= m <= 1000

 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        /* 如果给定的二维数组为空，则返回false */
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        /* 获取二维数组的行数和列数 */
        int m = matrix.size();
        int n = matrix[0].size();

        /* 初始化要查找的元素为第一行的最后一个元素，每一行的最后一个元素是该行最大的元素，如果都比该元素大，那就对于下一行的最后一个元素。如果比该元素小，说明target可能就在该行，向左查找target即可 */
        int i = 0, j = n - 1;
        /* 遍历二维数组 */
        while (i < m && j >= 0)
        {
            /* 如果matrix[i][j]==target,则返回true */
            if (matrix[i][j] == target)
                return true;

            /* 利用二位数组在行和列上递增的特性，如果当前元素>target,则说明target在该元素的左侧 */
            if (matrix[i][j] > target)
                --j;
            /* 如果当前元素<target，则说明target在下侧 */
            else
                ++i;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    // int m, n;
    // cin >> m >> n;
    // vector<vector<int>> matrix(m, vector<int>(n));
    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> matrix[i][j];

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target;
    cin >> target;
    Solution slt;
    cout << slt.findNumberIn2DArray(matrix, target);
    return 0;
}
