/* 3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成 */
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /* 滑动窗口：右指针遇到重复字符时，左指针跳到子串里第一个重复字符的位置，并且set把子串中重复字符前的字符去掉，右指针重新往右扩展 */
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> mySet;
        int len = s.size();
        int ptr = -1;
        int ans = 0;
        // 遍历字符串
        for (int i = 0; i < len; i++)
        {
            // 删除前一起始字符
            if (i)
            {
                mySet.erase(s[i - 1]);
            }
            // 对不同开头的字符，计算无重复最长字串
            while (ptr + 1 < len && !mySet.count(s[ptr + 1]))
            {
                mySet.insert(s[ptr + 1]);
                ptr++;
            }
            // 维护最大值，ptr-i+1为重复子串之间的间距，即为所求
            ans = max(ans, ptr - i + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    Solution slt;
    cout << slt.lengthOfLongestSubstring(s);
    return 0;
}
