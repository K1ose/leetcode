/* 118. 杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。





示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:

输入: numRows = 1
输出: [[1]]


提示:

1 <= numRows <= 30 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                ans[i].push_back(1);
            }
            if (i == 1)
            {
                ans[i].push_back(1);
                ans[i].push_back(1);
            }
            if (i >= 2)
            {
                ans[i].push_back(1);
                for (int j = 1; j <= i - 1; j++)
                {
                    ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
                ans[i].push_back(1);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    Solution slt;
    ans = slt.generate(n);
    return 0;
}
