/* 58. 最后一个单词的长度
简单
相关标签
相关企业
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大
子字符串
。



示例 1：

输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为5。
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为4。
示例 3：

输入：s = "luffy is still joyboy"
输出：6
解释：最后一个单词是长度为6的“joyboy”。


提示：

1 <= s.length <= 104
s 仅有英文字母和空格 ' ' 组成
s 中至少存在一个单词 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /* 逆序遍历字符串 s ，如果是空格就跳过， 如果不是就拼接到答案字符串 ans 中。同时，声明一个 flag 变量来标记是否目前已有单词计入，以此可以在最后一个单次计入后，停止遍历。 */
    int lengthOfLastWord(string s)
    {
        string ans;
        int n = s.size();
        while (n--)
        {
            /* 如果不是空格就计入 */
            if (s[n] != ' ')
            {
                ans.push_back(s[n]);
            }
            /* 如果是空格 */
            else
            {
                /* 且已经有单次计入 */
                if (!ans.empty())
                {
                    break;
                }
            }
        }
        return ans.size();
    }
};
