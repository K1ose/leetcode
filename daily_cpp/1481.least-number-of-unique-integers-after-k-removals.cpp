/* 1481. 不同整数的最少数目
中等
相关标签
相关企业
提示
给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。



示例 1：

输入：arr = [5,5,4], k = 1
输出：1
解释：移除 1 个 4 ，数组中只剩下 5 一种整数。
示例 2：

输入：arr = [4,3,1,1,3,3,2], k = 3
输出：2
解释：先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。


提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        vector<pair<int, int>> num_cnt_arr;
        unordered_map<int, int> num_cnt;
        for (auto num : arr)
        {
            num_cnt[num]++;
        }
        // cout << (num_cnt.size()) << endl;

        for (auto it : num_cnt)
        {
            num_cnt_arr.emplace_back(it);
        }
        // cout << (num_cnt_arr.size()) << endl;
        sort(num_cnt_arr.begin(), num_cnt_arr.end(), [](auto p1, auto p2)
             { return p1.second == p2.second ? p1.first < p1.first : p1.second < p2.second; });

        // for (int i = 0; i < num_cnt_arr.size(); i++)
        // {
        //     print_pair(num_cnt_arr[i]);
        // }
        int ans = num_cnt_arr.size();
        for (auto [_, cnt] : num_cnt_arr)
        {
            if (k >= cnt)
            {
                k -= cnt;
                ans--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    Solution slt;
    cout << slt.findLeastNumOfUniqueInts(arr, k);
    return 0;
}
