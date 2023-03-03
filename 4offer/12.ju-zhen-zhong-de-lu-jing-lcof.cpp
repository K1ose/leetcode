/* 剑指 Offer 12. 矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。



示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false



提示：

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board 和 word 仅由大小写英文字母组成

注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /* 设函数 check(i,j,k)表示判断以网格的 (i,j) 位置出发，能否搜索到单词 word[k..]，其中 word[k..] 表示字符串 word 从第 k 个字符开始的后缀子串。如果能搜索到，则返回 truetrue，反之返回 false。函数 check(i,j,k) 的执行步骤如下：

        - 如果 board[i][j]≠s[k]，当前字符不匹配，直接返回 false。
        - 如果当前已经访问到字符串的末尾，且对应字符依然匹配，此时直接返回 true。
        - 否则，遍历当前位置的所有相邻位置。如果从某个相邻位置出发，能够搜索到子串 word[k+1..]，则返回 true，否则返回 false。

    这样，我们对每一个位置 (i,j) 都调用函数 check(i,j,0) 进行检查：只要有一处返回 true，就说明网格中能够找到相应的单词，否则说明不能找到。

    为了防止重复遍历相同的位置，需要额外维护一个与 board 等大的 visited 数组，用于标识每个位置是否被访问过。每次遍历相邻位置时，需要跳过已经被访问的位置。 */

    /// @brief
    /// @param board - 待搜索的二维数组
    /// @param visited - 记录board[i][j]位置是否被访问过的二维数组
    /// @param i - 第i行
    /// @param j - 第j列
    /// @param s - 匹配字符串
    /// @param k - 当前匹配的字符串下标，当前匹配字符s[k]
    /// @return - true 表示当前位置的四周存在匹配下一字符的位置， false 表示四周都不匹配
    bool check(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &s, int k)
    {
        /* board[i][j]≠s[k]，当前字符不匹配，直接返回 false */
        if (board[i][j] != s[k])
        {
            return false;
        }
        /* 当前已经访问到字符串的末尾，且对应字符依然匹配，此时直接返回 true */
        else if (k == s.size() - 1)
        {
            return true;
        }

        /* 表示当前位置已被访问 */
        visited[i][j] = true;

        /* 方向向量 */
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        bool res = false;

        /* 遍历周围四个方向 */
        for (auto direction : directions)
        {
            /* 新的位置下标 */
            int new_i = i + direction.first, new_j = j + direction.second;

            /* 判断下标是否合法 */
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size())
            {
                /* 合法，则判断新的下标位置是否被访问过 */
                if (!visited[new_i][new_j])
                {
                    /* 未被访问过，则检查新下标位置是否存在匹配的字符 */
                    bool flag = check(board, visited, new_i, new_j, s, k + 1);
                    /* 匹配 */
                    if (flag)
                    {
                        res = true;
                        break;
                    }
                }
            }
        }
        /* 如果当前位置的四个方向都没有匹配下一个字符，则将当前位置的visited[i][j]设置为未访问，并返回到上一位置，继续查找上一位置的剩余方向是否有匹配 */
        visited[i][j] = false;
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        /* 遍历寻找匹配字符串起始字符的位置 */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /* 开始搜索 */
                bool flag = check(board, visited, i, j, word, 0);
                if (flag)
                {
                    return true;
                }
            }
        }
        return false;
    }

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
