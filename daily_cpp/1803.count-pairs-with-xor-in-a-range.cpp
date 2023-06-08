/* 1803. 统计异或值在范围内的数对有多少
给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数：low 和 high ，请返回 漂亮数对 的数目。

漂亮数对 是一个形如 (i, j) 的数对，其中 0 <= i < j < nums.length 且 low <= (nums[i] XOR nums[j]) <= high 。



示例 1：

输入：nums = [1,4,2,7], low = 2, high = 6
输出：6
解释：所有漂亮数对 (i, j) 列出如下：
    - (0, 1): nums[0] XOR nums[1] = 5
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
示例 2：

输入：nums = [9,8,4,2,1], low = 5, high = 14
输出：8
解释：所有漂亮数对 (i, j) 列出如下：
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5


提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 2 * 104
1 <= low <= high <= 2 * 104 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

struct Trie
{
    /*
        两个数组，son[0], son[1]
        son[0] - 左子树
        son[1] - 右子树
    */
    array<Trie *, 2> son{nullptr, nullptr};

    int sum;
    Trie() : sum(0) {} /* 初始化 sum 为 0 */
};

class Solution
{
public:
    /* 暴力破解 O(n)=n^2 */
    int countPairs_brute_force(vector<int> &nums, int low, int high)
    {
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if ((nums[i] ^ nums[j]) <= high && (nums[i] ^ nums[j]) >= low)
                {
                    count++;
                }
            }
        }
        return count;
    }

    /* 大佬的编译器优化后的暴力算法 */
#define us unsigned short
    us a[20015];

    int countPairs_compiler(vector<int> &_a, us l, us r)
    {
        int n = _a.size(), ans = 0;
        int d = 0;
        for (int i = 0; i < n; ++i)
            a[i] = _a[i];
        sort(a, a + n);
        for (us *i = a, *end = i + n; i != end; ++i)
        {
            if (i > a && *i == *(i - 1))
            {
                ans += d;
                continue;
            }
            us *j = i + 1, *end1 = end - 8;
            d = 0;
            for (; j < end1; j += 8)
            {
                us x = *i ^ *j, x1 = *i ^ *(j + 1), x2 = *i ^ *(j + 2), x3 = *i ^ *(j + 3),
                   x4 = *i ^ *(j + 4), x5 = *i ^ *(j + 5), x6 = *i ^ *(j + 6), x7 = *i ^ *(j + 7);
                d += (x >= l && x <= r) + (x1 >= l && x1 <= r) + (x2 >= l && x2 <= r) + (x3 >= l && x3 <= r) + (x4 >= l && x4 <= r) + (x5 >= l && x5 <= r) + (x6 >= l && x6 <= r) + (x7 >= l && x7 <= r);
            }
            for (; j < end; ++j)
                d += (*i ^ *j) >= l && (*i ^ *j) <= r;
            ans += d;
        }
        return ans;
    }
    /* 字典树 */
    void add(int num)
    {
        Trie *cur = root;
        for (int k = HIGH_BIT; k >= 0; k--)
        {
            int bit = (num >> k) & 1;
            if (cur->son[bit] == nullptr)
            {
                cur->son[bit] = new Trie();
            }
            cur = cur->son[bit];
            cur->sum++;
        }
    }

    int get(int num, int x)
    {
        Trie *cur = root;
        int sum = 0;
        for (int k = HIGH_BIT; k >= 0; k--)
        {
            int r = (num >> k) & 1;
            if ((x >> k) & 1)
            {
                if (cur->son[r] != nullptr)
                {
                    sum += cur->son[r]->sum;
                }
                if (cur->son[r ^ 1] == nullptr)
                {
                    return sum;
                }
                cur = cur->son[r ^ 1];
            }
            else
            {
                if (cur->son[r] == nullptr)
                {
                    return sum;
                }
                cur = cur->son[r];
            }
            sum += cur->sum;
            return sum;
        }
    }

    int f(vector<int> &nums, int x)
    {
        int res = 0;
        root = new Trie();
        for (int i = 0; i < nums.size(); i++)
        {
            add(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }

    int countPairs(vector<int> &nums, int low, int high)
    {
        return f(nums, high) - f(nums, low - 1);
    }

private:
    Trie *root = nullptr;               /* 根节点 */
    static constexpr int HIGH_BIT = 14; /* 最高位的二进制编号为14 */
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int low, high;
    cin >> low >> high;
    Solution slt;
    cout << slt.countPairs(nums, low, high) << endl;

    return 0;
}
