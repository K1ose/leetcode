/* 2418. 按身高排序
给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。

对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。

请按身高 降序 顺序返回对应的名字数组 names 。



示例 1：

输入：names = ["Mary","John","Emma"], heights = [180,165,170]
输出：["Mary","Emma","John"]
解释：Mary 最高，接着是 Emma 和 John 。
示例 2：

输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
输出：["Bob","Alice","Bob"]
解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。


提示：

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] 由大小写英文字母组成
heights 中的所有值互不相同 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        unordered_map<int, string> map;
        for (int i = 0; i < n; i++)
        {
            map[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end(), [&](int h1, int h2)
             { return h1 > h2; });
        for (int i = 0; i < n; i++)
        {
            names[i] = map[heights[i]];
        }
        return names;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> heights = {180, 165, 170};
    vector<string> names = {"Mary", "John", "Emma"};
    Solution slt;
    print_vec1d_arr(slt.sortPeople(names, heights));
    return 0;
}
