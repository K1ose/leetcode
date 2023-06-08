/* 1686. 石子游戏 VI
Alice 和 Bob 轮流玩一个游戏，Alice 先手。

一堆石子里总共有 n 个石子，轮到某个玩家时，他可以 移出 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 不一样的的评判标准 。双方都知道对方的评判标准。

给你两个长度为 n 的整数数组 aliceValues 和 bobValues 。aliceValues[i] 和 bobValues[i] 分别表示 Alice 和 Bob 认为第 i 个石子的价值。

所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 最优策略 进行游戏。

请你推断游戏的结果，用如下的方式表示：

如果 Alice 赢，返回 1 。
如果 Bob 赢，返回 -1 。
如果游戏平局，返回 0 。


示例 1：

输入：aliceValues = [1,3], bobValues = [2,1]
输出：1
解释：
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。
示例 2：

输入：aliceValues = [1,2], bobValues = [3,1]
输出：0
解释：
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。
示例 3：

输入：aliceValues = [2,4,3], bobValues = [1,6,7]
输出：-1
解释：
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。


提示：

n == aliceValues.length == bobValues.length
1 <= n <= 105
1 <= aliceValues[i], bobValues[i] <= 100 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /* 注意读题，Alice是知道Bob的评分标准的，所以还要考虑对方的分值，不能只考虑自己的分值 */
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        // TODO

        int ans;
        int alice_count = 0, bob_count = 0;
        int t = bobValues.size();
        while (t--)
        {
            int max_alice = *max_element(aliceValues.begin(), aliceValues.end());

            if (max_alice != 0)
            {
                int max_pos = max_element(aliceValues.begin(), aliceValues.end()) - aliceValues.begin();
                alice_count += aliceValues[max_pos];
                aliceValues[max_pos] = 0, bobValues[max_pos] = 0;

                max_pos = max_element(bobValues.begin(), bobValues.end()) - bobValues.begin();
                bob_count += bobValues[max_pos];
                aliceValues[max_pos] = 0, bobValues[max_pos] = 0;
            }
        }
        if (alice_count == bob_count)
        {
            return 0;
        }
        return alice_count > bob_count ? 1 : -1;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> alice_values(n), bob_values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> alice_values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bob_values[i];
    }

    Solution slt;
    cout << slt.stoneGameVI(alice_values, bob_values) << endl;
    return 0;
}
