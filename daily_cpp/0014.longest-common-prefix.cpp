/* 14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。


提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string str;
        int str_len = strs[0].size();
        int str_count = strs.size();

        for (int i = 0; i < str_len; i++) /* 遍历字符串的每一个字符 */
        {
            char c = strs[0][i]; /* 比较字符对象 */

            /* 遍历数组中的每一个字符串，进行比较 */
            for (int j = 1; j < str_count; j++)
            {
                /* 如果访问元素时超出某个字符串长度 或者 不匹配， 则截取相同的部分并返回 */
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        /* 全匹配直接返回 strs[0] */
        return strs[0];
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    Solution slt;
    cout << slt.longestCommonPrefix(strs) << endl;
    return 0;
}
