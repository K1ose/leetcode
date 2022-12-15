/* 22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]


提示：

1 <= n <= 8
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /// @brief 回溯算法
    /// @param ans vector<string>， 存放每一种解的数组
    /// @param cur string， 当前操作数组
    /// @param left int，左括号数量
    /// @param right int，右括号数量
    /// @param n int， 存在n对括号
    void backtrack(vector<string> &ans, string &cur, int left, int right, int n)
    {
        /* 结束条件: 当长度达到2n时，说明完成了一次匹配，将解存放到ans数组中，结束当前递归分支 */
        if (cur.size() == 2 * n)
        {
            ans.push_back(cur);
            return;
        }

        /* 只要左括号还有剩余，则选择左括号 */
        if (left > 0)
        {
            cur.push_back('(');
            backtrack(ans, cur, left - 1, right, n);
            cur.pop_back();
        }

        /* 如果右括号多于左括号，则可以选择右括号 */
        if (right > left)
        {
            cur.push_back(')');
            backtrack(ans, cur, left, right - 1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string cur;
        backtrack(res, cur, n, n, n);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution slt;
    vector<string> strs;
    strs = slt.generateParenthesis(n);
    for (int i = 0; i < n; i++)
        cout << strs[i] << " ";
    return 0;
}
