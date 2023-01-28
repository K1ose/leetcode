/* 1288. 删除被覆盖区间
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。



示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。


提示：​​​​​​

1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j] */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int size = intervals.size();
        int count = 0;
        int max_right = -1;
        int prev_left = -1;
        sort(intervals.begin(), intervals.end());
        for (auto interval : intervals)
        {
            if (max_right >= interval[1])
            {
                count++;
            }
            else
            {
                if (prev_left == interval[0])
                {
                    count++;
                }
            }
            prev_left = interval[0];
            max_right = max(max_right, interval[1]);
            // TODO
        }
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     for (int j = 0; j < 2; j++)
        //     {
        //         cout << intervals[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return size - count;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            cin >> intervals[i][j];
        }
    }

    Solution slt;
    cout << slt.removeCoveredIntervals(intervals);
    return 0;
}
