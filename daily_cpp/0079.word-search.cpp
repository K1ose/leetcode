/* 79. 单词搜索

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true

示例 3：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false



提示：

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board 和 word 仅由大小写英文字母组成



进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* dfs */
    int m, n;
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> flags(m, vector<bool>(n));
                    if (dfs(board, word, flags, 0, i, j))
                        return true;
                }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &flags, int index, int x, int y)
    {
        if (index == word.size())
            return true;
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[index] || flags[x][y])
            return false;
        flags[x][y] = 1;
        bool res = dfs(board, word, flags, index + 1, x + 1, y) || dfs(board, word, flags, index + 1, x, y + 1) || dfs(board, word, flags, index + 1, x - 1, y) || dfs(board, word, flags, index + 1, x, y - 1);
        flags[x][y] = 0;
        return res;
    }
};
