/* 2660. 保龄球游戏的获胜者 显示英文描述
通过的用户数2267
尝试过的用户数2518
用户总通过次数2301
用户总提交次数8128
题目难度Easy
给你两个下标从 0 开始的整数数组 player1 和 player2 ，分别表示玩家 1 和玩家 2 击中的瓶数。

保龄球比赛由 n 轮组成，每轮的瓶数恰好为 10 。

假设玩家在第 i 轮中击中 xi 个瓶子。玩家第 i 轮的价值为：

如果玩家在前两轮中击中了 10 个瓶子，则为 2xi 。
否则，为 xi 。
玩家的得分是其 n 轮价值的总和。

返回

如果玩家 1 的得分高于玩家 2 的得分，则为 1 ；
如果玩家 2 的得分高于玩家 1 的得分，则为 2 ；
如果平局，则为 0 。


示例 1：

输入：player1 = [4,10,7,9], player2 = [6,5,2,3]
输出：1
解释：player1 的得分是 4 + 10 + 2*7 + 2*9 = 46 。
player2 的得分是 6 + 5 + 2 + 3 = 16 。
player1 的得分高于 player2 的得分，所以 play1 在比赛中获胜，答案为 1 。
示例 2：

输入：player1 = [3,5,7,6], player2 = [8,10,10,2]
输出：2
解释：player1 的得分是 3 + 5 + 7 + 6 = 21 。
player2 的得分是 8 + 10 + 2*10 + 2*2 = 42 。
player2 的得分高于 player1 的得分，所以 play2 在比赛中获胜，答案为 2 。
示例 3：

输入：player1 = [2,3], player2 = [4,1]
输出：0
解释：player1 的得分是 2 + 3 = 5 。
player2 的得分是 4 + 1 = 5 。
player1 的得分等于 player2 的得分，所以这一场比赛平局，答案为 0 。


提示：

n == player1.length == player2.length
1 <= n <= 1000
0 <= player1[i], player2[i] <= 10 */

#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int calScore(vector<int> arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 2)
        {
            return arr[0] == 10 ? arr[0] + arr[1] * 2 : arr[0] + arr[1];
        }
        int player_flag = 2;
        int sum = arr[0];
        if (arr[0] == 10)
        {
            sum += arr[1] * 2;
        }
        else
        {
            sum += arr[1];
        }
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i - 2] == 10 || arr[i - 1] == 10)
            {
                sum += arr[i] * 2;
            }
            else
            {
                sum += arr[i];
            }
        }
        return sum;
    }
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int res;
        int player1_sum = calScore(player1);
        int player2_sum = calScore(player2);
        if (player1_sum > player2_sum)
        {
            return 1;
        }
        else if (player1_sum < player2_sum)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> player1 = {9, 7, 10, 7};  /* 9+7+10+14= 40 */
    vector<int> player2 = {10, 2, 4, 10}; /* 10+4+8+10=32 */
    Solution slt;
    cout << slt.isWinner(player1, player2) << endl;
    return 0;
}
