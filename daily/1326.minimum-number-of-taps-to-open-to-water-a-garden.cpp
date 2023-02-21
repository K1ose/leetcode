/* 1326. 灌溉花园的最少水龙头数目

在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。

花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。

给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。

请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。



示例 1：

输入：n = 5, ranges = [3,4,1,1,0,0]
输出：1
解释：
点 0 处的水龙头可以灌溉区间 [-3,3]
点 1 处的水龙头可以灌溉区间 [-3,5]
点 2 处的水龙头可以灌溉区间 [1,3]
点 3 处的水龙头可以灌溉区间 [2,4]
点 4 处的水龙头可以灌溉区间 [4,4]
点 5 处的水龙头可以灌溉区间 [5,5]
只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。

示例 2：

输入：n = 3, ranges = [0,0,0,0]
输出：-1
解释：即使打开所有水龙头，你也无法灌溉整个花园。



提示：

    1 <= n <= 104
    ranges.length == n + 1
    0 <= ranges[i] <= 100

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /* 动态规划 */
    int minTaps(int n, vector<int> &ranges)
    {
        /* 记录每一个水龙头在[0,n]的覆盖范围[start_i, end_i]，保存在taps_range中 */
        vector<pair<int, int>> taps_range;
        for (int i = 0; i <= n; i++)
        {
            int start = max(0, i - ranges[i]); /* 可覆盖的起始点 */
            int end = min(n, i + ranges[i]);   /* 可覆盖的终点 */
            taps_range.emplace_back(start, end);
        }

        /* 将可覆盖起始点按从小到大排序 */
        sort(taps_range.begin(), taps_range.end());

        /* dp[i] 表示覆盖区间[0,i]所需的最少的水龙头数目 */
        vector<int> dp(n + 1, __INT_MAX__); /* 初始化 */

        dp[0] = 0; /* 覆盖区间[0,0]所需的水龙头为0 */

        for (auto [start, end] : taps_range)
        {

            /* 一个水龙头的覆盖区域中，当前位置的所需水龙头数目为该水龙头覆盖区域起始点 */
            if (dp[start] == __INT_MAX__)
            {
                return -1;
            }

            for (int j = start; j <= end; j++)
            {
                /* j位置所需最少水龙头数目为 min(dp[j], dp[start] + 1 ，即要么有水龙头已经覆盖过了，要么就是新的未覆盖的点，所以在这个水龙头的覆盖区间内，所需的水龙头数量，为起始点所需水龙头数+1 */
                dp[j] = min(dp[j], dp[start] + 1);
            }
        }
        return dp[n];
    }

    /* 贪心 */
    int minTaps_greedy(int n, vector<int> ranges)
    {
        vector<int> right_range(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            /* 对于覆盖起始点为start的点而言，维护其向右所能够覆盖的最大范围 */
            right_range[start] = max(right_range[start], end);
        }

        int cur_right = 0; /* 在当前点，能由一个水龙头覆盖的最大区间右值 */
        int count = 0;     /* 所需水龙头数量 */
        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            cur_right = max(right_range[i], cur_right);
            if (cur_right == i) /* 当前点覆盖区间最右值为当前点，表示其右侧的点无法完全覆盖 */
            {
                return -1;
            }
            if (pre == i) /* 如果当前点是先前覆盖区间最右值，则说明需要新的水龙头来覆盖右侧的点 */
            {
                count++;
                pre = cur_right;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ranges = {3, 4, 1, 1, 2, 0, 3};
    Solution slt;
    cout << slt.minTaps_greedy(n, ranges) << endl;
    return 0;
}
