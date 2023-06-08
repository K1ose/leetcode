/* 1774. 最接近目标价格的甜点成本
你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：

必须选择 一种 冰激凌基料。
可以添加 一种或多种 配料，也可以不添加任何配料。
每种类型的配料 最多两份 。
给你以下三个输入：

baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回 成本相对较低 的一种。



示例 1：

输入：baseCosts = [1,7], toppingCosts = [3,4], target = 10
输出：10
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 7
- 选择 1 份 0 号配料：成本 1 x 3 = 3
- 选择 0 份 1 号配料：成本 0 x 4 = 0
总成本：7 + 3 + 0 = 10 。
示例 2：

输入：baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
输出：17
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 3
- 选择 1 份 0 号配料：成本 1 x 4 = 4
- 选择 2 份 1 号配料：成本 2 x 5 = 10
- 选择 0 份 2 号配料：成本 0 x 100 = 0
总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
示例 3：

输入：baseCosts = [3,10], toppingCosts = [2,5], target = 9
输出：8
解释：可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
示例 4：

输入：baseCosts = [10], toppingCosts = [1], target = 1
输出：10
解释：注意，你可以选择不添加任何配料，但你必须选择一种基料。


提示：

n == baseCosts.length
m == toppingCosts.length
1 <= n, m <= 10
1 <= baseCosts[i], toppingCosts[i] <= 104
1 <= target <= 104
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff

class Solution
{
public:
    /* 动态规划 01背包 */
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        /* 获得最小基料 */
        int min_base_cost = *min_element(baseCosts.begin(), baseCosts.end());

        /* 如果最小基料的开销已经大于预算，那么直接返回最小基料作为方案 */
        if (min_base_cost > target)
            return min_base_cost;

        /* 初始化开销，当方案开销y大于target*2-min_base_cost时，跳过。因为最小集料与预算的距离为target-min_base_cost，而当 y > target*2-min_base_cost时，方案开销y与预算的距离为y-target > target-min_base_cost */
        int res = target * 2 - min_base_cost;

        /* 设bool valid[i]为开销为i时是否存在合法的方案，是则存储true，否则存储false */
        vector<bool> valid(target + 1, false);

        /* 遍历基料，将小于等于预算的方案标记为true,如果基料大于预算，则选取最小基料作为开销 */
        for (auto &bc : baseCosts)
        {
            if (bc <= target)
                valid[bc] = true;
            else
                res = min(res, bc);
        }
        // TODO
    }

    /* 回溯 */
    void dfs(const vector<int> &topping_costs, int top_type, int cur_cost, int &res, const int &target)
    {
        /* 剪枝操作，如果当前开销已经超预算(cur_cost-target>0)，则返回成本最小的选择，即min_base_cost，也就是res */
        if (abs(res - target) < cur_cost - target)
            return;

        /* 如果当前开销更接近预算，则替换 */
        else if (abs(res - target) >= abs(cur_cost - target))
        {
            if (abs(res - target) > abs(cur_cost - target))
                res = cur_cost;

            /* 两种方案的开销都一样接近时，选择成本更小的 */
            else
                res = min(res, cur_cost);
        }

        /* 当p为顶料种类大小，则返回 */
        if (top_type == topping_costs.size())
            return;

        /* 开销从大到小进行回溯：
        1. 考虑每种顶料添加两份
        2. 考虑每种顶料添加一份
        3. 考虑不添加顶料 */
        dfs(topping_costs, top_type + 1, cur_cost + topping_costs[top_type] * 2, res, target);
        dfs(topping_costs, top_type + 1, cur_cost + topping_costs[top_type], res, target);
        dfs(topping_costs, top_type + 1, cur_cost, res, target);
    }

    int closest_cost(vector<int> &base_costs, vector<int> &topping_costs, int target)
    {
        /* 选取最小基料 */
        int res = *min_element(base_costs.begin(), base_costs.end());

        /* 遍历基料 */
        for (auto &bc : base_costs)
        {
            dfs(topping_costs, 0, bc, res, target);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int m, n, target;
    cin >> m >> n >> target;
    vector<int> base_costs(m);
    vector<int> topping_costs(n);
    for (int i = 0; i < m; i++)
        cin >> base_costs[i];
    for (int i = 0; i < n; i++)
        cin >> topping_costs[i];

    Solution slt;
    cout << slt.closestCost(base_costs, topping_costs, target) << endl;
    cout << slt.closest_cost(base_costs, topping_costs, target) << endl;
    return 0;
}
