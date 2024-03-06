/* 389. 找不同
简单
相关标签
相关企业
给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。



示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"


提示：

0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int char_arr[26] = {0};
        for (char c : s)
        {
            char_arr[c - 'a']++;
        }
        for (char c : t)
        {
            char_arr[c - 'a']--;
            if (char_arr[c - 'a'] == -1)
            {
                return c;
            }
        }
        return ' ';
    }
};

int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    string t = "afdcebfg";
    Solution slt;
    cout << slt.findTheDifference(s, t) << endl;
    return 0;
}
