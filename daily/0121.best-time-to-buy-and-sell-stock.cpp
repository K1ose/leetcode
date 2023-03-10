/* 121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。



示例 1：

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。


提示：

1 <= prices.length <= 105
0 <= prices[i] <= 104
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* 暴力模拟 */
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0; /* 如果亏本的话就不抛售 */
        int len = prices.size();
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                max_profit = max(max_profit, prices[j] - prices[i]);
        return max_profit;
    }

    /* 找到最小股价（动态），计算这之后每天的利润，找到利润最大值 */
    int maxProfit_min(vector<int> &prices)
    {
        int min_price = INT32_MAX;
        int max_profit = 0;
        for (auto x : prices)
        {
            min_price = min(min_price, x);
            // if (x == min_price)
            //     continue;
            max_profit = max(max_profit, x - min_price);
        }
        return max_profit;
    }

    /* 双指针（不固定窗口大小的窗口滑动） */
    int maxProfit_doubleptr(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }
        int left = 0, right = 0;
        int max_profit = 0;
        while (right < n)
        {
            int cur_profit = prices[right] - prices[left];
            while (cur_profit < 0)
            {
                left = right;
                right++;
            }
            max_profit = max(max_profit, cur_profit);
            right++;
        }
        return max_profit;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution slt;
    cout << slt.maxProfit_min(nums) << endl;
    return 0;
}
