/* 面试题61. 扑克牌中的顺子

从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。



示例 1:

输入: [1,2,3,4,5]
输出: True



示例 2:

输入: [0,0,1,2,5]
输出: True



限制：

数组长度为 5

数组的数取值为 [0, 13] .
 */

#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    /* 转换为滑动窗口问题 */
    bool isStraight(vector<int> &nums)
    {
        int pokers[14] = {0}, joker = 0;
        for (auto num : nums)
        {
            if (num == 0)
            {
                joker++;
            }
            else
            { /* 如果不是大小王，并且已经存在相同的牌，则不可能组成顺子 */
                if (pokers[num])
                {
                    return false;
                }
            }
            pokers[num]++;
        }

        int left = 1, lsum = 0, rsum = 0;
        int cnt = 0;
        for (int right = 1; right < 14; right++)
        {
            rsum += 1 - pokers[right];

            while (lsum < rsum - joker)
            {
                lsum += 1 - pokers[left];
                left++;
            }
            cnt = max(cnt, right - left + 1);
            if (cnt == 5)
            {
                return true;
            }
        }
        return false;
    }

    /* 最大最小牌差值 */
    bool isStraight_minmax(vector<int> nums)
    {
        int max_poker = 0, min_poker = 13;
        unordered_set<int> poker;
        for (int num : nums)
        {
            if (num != 0)
            {
                max_poker = max(num, max_poker);
                min_poker = min(num, min_poker);
                if (poker.count(num))
                {
                    return false;
                }
                poker.emplace(num);
            }
        }
        return max_poker - min_poker < 5;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 0, 2, 4, 6};
    Solution slt;
    cout << slt.isStraight_minmax(nums) << endl;
    return 0;
}
