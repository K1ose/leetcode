/* 2185. 统计包含给定前缀的字符串
给你一个字符串数组 words 和一个字符串 pref 。

返回 words 中以 pref 作为 前缀 的字符串的数目。

字符串 s 的 前缀 就是  s 的任一前导连续字符串。



示例 1：

输入：words = ["pay","attention","practice","attend"], pref = "at"
输出：2
解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
示例 2：

输入：words = ["leetcode","win","loops","success"], pref = "code"
输出：0
解释：不存在以 "code" 作为前缀的字符串。


提示：

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] 和 pref 由小写英文字母组成 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int len = pref.size();
        int count = 0;
        for (string s : words)
        {
            int i;
            for (i = 0; i < len; i++)
            {
                if (pref[i] != s[i])
                    break;
            }
            if (i == len)
                count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string pref;
    cin >> pref;
    Solution slt;
    cout << slt.prefixCount(words, pref) << endl;
    return 0;
}
