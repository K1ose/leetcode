/* 1023. 驼峰式匹配
如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）

给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。



示例 1：

输入：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
输出：[true,false,true,true,false]
示例：
"FooBar" 可以这样生成："F" + "oo" + "B" + "ar"。
"FootBall" 可以这样生成："F" + "oot" + "B" + "all".
"FrameBuffer" 可以这样生成："F" + "rame" + "B" + "uffer".
示例 2：

输入：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
输出：[true,false,true,false,false]
解释：
"FooBar" 可以这样生成："Fo" + "o" + "Ba" + "r".
"FootBall" 可以这样生成："Fo" + "ot" + "Ba" + "ll".
示例 3：

输出：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
输入：[false,true,false,false,false]
解释：
"FooBarTest" 可以这样生成："Fo" + "o" + "Ba" + "r" + "T" + "est".


提示：

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
所有字符串都仅由大写和小写英文字母组成。
 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    bool check(string query, string pattern)
    {
        int idx_q = 0, idx_p = 0, QSize = query.size(), PSize = pattern.size();
        while (idx_q < QSize && idx_p < PSize)
        {
            /* 如果当前字符匹配，则两个指针同时向右移动 */
            if (query[idx_q] == pattern[idx_p])
            {
                idx_q++;
                idx_p++;
            }
            /* 如果匹配串是小写字符，则匹配串指针向右移动 */
            else if (query[idx_q] >= 'a' && query[idx_q] <= 'z')
            {
                idx_q++;
            }
            /* 如果匹配串字符不是小写字符，也不与模式串匹配，则返回false */
            else
            {
                return false;
            }
        }
        /* 跳出while循环的可能有：
        1. return false
        2. idx_q == QSize， 即：匹配串匹配结束，可能模式串未完全匹配
        3. idx_p == PSize， 即：模式串匹配结束，可能匹配串未完全匹配 */

        /* 如果模式串没有完全匹配，返回false */
        if (idx_p < PSize)
        {
            return false;
        }
        /* 此时模式串匹配完全，如果匹配串没有完全匹配 */
        if (idx_q < QSize)
        {
            /* 检测匹配串后续有无大些字母 */
            while (idx_q < QSize && query[idx_q] >= 'a' && query[idx_q] <= 'z')
            {
                idx_q++;
            }
        }
        /* 匹配串完全匹配，模式串完全匹配 */
        return idx_q == QSize;
    }

    /* 双指针 */
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        for (string query : queries)
        {
            res.push_back(check(query, pattern));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string pattern = "FoBa";
    vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    // string query;
    // while (getline(cin, query) && !query.empty())
    // {
    //     queries.push_back(query);
    // }
    // print_vec1d_arr(queries);

    Solution slt;
    print_vec1d_arr(slt.camelMatch(queries, pattern));
    return 0;
}
