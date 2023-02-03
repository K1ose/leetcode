/* 2389. 和有限的最长子序列
给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。

返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度  。

子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。



示例 1：

输入：nums = [4,5,2,1], queries = [3,10,21]
输出：[2,3,4]
解释：queries 对应的 answer 如下：
- 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
- 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
- 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
示例 2：

输入：nums = [2,3,4,5], queries = [1]
输出：[0]
解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。


提示：

n == nums.length
m == queries.length
1 <= n, m <= 1000
1 <= nums[i], queries[i] <= 106 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int len = queries.size();
        vector<int> answers;
        sort(nums.begin(), nums.end());
        for (int query : queries)
        {
            int sum = 0, count = 0;
            for (int num : nums)
            {
                if (sum + num <= query)
                {
                    count++;
                    sum += num;
                }
            }
            answers.push_back(count);
        }
        return answers;
    }
};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<int> nums(m);
    vector<int> queries(n);
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i];
    }

    vector<int> answers(n);
    Solution slt;
    answers = slt.answerQueries(nums, queries);
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << " ";
    }
    cout << endl;
    return 0;
}
