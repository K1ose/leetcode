/* 459. 重复的子字符串
简单
相关标签
相关企业
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。



示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
示例 2:

输入: s = "aba"
输出: false
示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)


提示：

1 <= s.length <= 104
s 由小写英文字母组成 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    bool kmp(const string &pattern)
    {
        int n = pattern.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i)
        {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i])
            {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i])
            {
                fail[i] = j + 1;
            }
        }
        return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
    }

    bool repeatedSubstringPattern(string s)
    {
        return kmp(s);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
