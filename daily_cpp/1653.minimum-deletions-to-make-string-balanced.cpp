/* 1653. 使字符串平衡的最少删除次数

给你一个字符串 s ，它仅包含字符 'a' 和 'b'​​​​ 。

你可以删除 s 中任意数目的字符，使得 s 平衡 。当不存在下标对 (i,j) 满足 i < j ，且 s[i] = 'b' 的同时 s[j]= 'a' ，此时认为 s 是 平衡 的。

请你返回使 s 平衡 的 最少 删除次数。



示例 1：

输入：s = "aababbab"
输出：2
解释：你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aababbab" -> "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aababbab" -> "aabbbb"）。

示例 2：

输入：s = "bbaaaaabb"
输出：2
解释：唯一的最优解是删除最前面两个字符。



提示：

    1 <= s.length <= 105
    s[i] 要么是 'a' 要么是 'b'​ 。​

 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    /* 要使得字符串平衡，所有的a必须在左侧，左右的b必须在右侧，那么中间必然会有一个分界线，可以枚举所有的分界线(n-1条)，计算其右侧的a的数目，在分界线右移时，如果左侧的字母是a，则减少删除次数，如果是b则增加删除次数，维护其最小值即可 */
    int minimumDeletions(string s)
    {
        int count = 0;
        for (char c : s)
        {
            count += 'b' - c; /* 如果字母为 a ，则count+=1 */
        }

        int res = count;
        for (char c : s)
        {
            count += (c - 'a') * 2 - 1;
            /* a->-1 b->1,
            这样做可以提高效率：CPU 在遇到分支（条件跳转指令）时会预测代码要执行哪个分支，如果预测正确，CPU 就会继续按照预测的路径执行程序。但如果预测失败，CPU 就需要回滚之前的指令并加载正确的指令，以确保程序执行的正确性。字符 ‘a’‘a’ 和 ‘b’‘b’ 可以认为是随机出现的，在这种情况下分支预测就会有 50% 的概率失败。失败导致的回滚和加载操作需要消耗额外的 CPU 周期，如果能用较小的代价去掉分支，对于本题的情况必然可以带来效率上的提升。但是不要在业务代码中使用这类手法，会降低代码可读性 */
            /* if (c == 'b')
            {
                count++;
            }
            else
            {
                count--;
            } */
            res = min(count, res);
        }
        return res;
    }

    /* 动态规划 */
    /* 设f[i] 为第i个字符时的删除次数。考虑 最后一个字符，如果是：
    - b，则保留；
    - a，则：
        - 删除，f[i] = f[i]+1；
        - 保留，删除i前的所有b,这里用cnt_b来存储i前的所有b，则删除的次数为 cnt_b
        因此，f[i] = min(f[i]+1, cnt_b) */

    int mininumDeletions_dp(string s)
    {
        int cnt_b = 0, f = 0;
        for (char c : s)
        {
            /* 虽然是一次遍历，但是if-else来匹配随机数据导致了效率反而不如上面的两次遍历的方法 */
            if (c == 'b')
            {
                cnt_b++;
            }
            else
            {
                f = min(cnt_b, f + 1);
            }
        }
        return f;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
