/* 2379. 得到 K 个黑块的最少涂色次数

给你一个长度为 n 下标从 0 开始的字符串 blocks ，blocks[i] 要么是 'W' 要么是 'B' ，表示第 i 块的颜色。字符 'W' 和 'B' 分别表示白色和黑色。

给你一个整数 k ，表示想要 连续 黑色块的数目。

每一次操作中，你可以选择一个白色块将它 涂成 黑色块。

请你返回至少出现 一次 连续 k 个黑色块的 最少 操作次数。



示例 1：

输入：blocks = "WBBWWBBWBW", k = 7
输出：3
解释：
一种得到 7 个连续黑色块的方法是把第 0 ，3 和 4 个块涂成黑色。
得到 blocks = "BBBBBBBWBW" 。
可以证明无法用少于 3 次操作得到 7 个连续的黑块。
所以我们返回 3 。

示例 2：

输入：blocks = "WBWBBBW", k = 2
输出：0
解释：
不需要任何操作，因为已经有 2 个连续的黑块。
所以我们返回 0 。



提示：

    n == blocks.length
    1 <= n <= 100
    blocks[i] 要么是 'W' ，要么是 'B' 。
    1 <= k <= n

 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        /* 记录起始窗口中需要翻转的次数 */
        int cnt = 0, left = 0, right = 0, n = blocks.size();
        for (; right < k; right++)
        {
            if (blocks[right] == 'W')
            {
                cnt++;
            }
        }

        int res = cnt;
        /* 窗口右移 */
        for (; right < n; right++, left++)
        {
            /* 当新添加的字符为'W'时，表示翻转次数需要加一 */
            cnt += (blocks[right] - 'B') % 20;

            /* 如果原窗口第一个字符为'W'时，需要减去一次翻转次数 */
            cnt -= (blocks[left] - 'B') % 20;

            /* 维护翻转次数的最小值 */
            res = min(cnt, res);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string blocks = "WBWBBBW";
    Solution slt;
    cout << slt.minimumRecolors(blocks, 2) << endl;
    return 0;
}
