/* 剑指 Offer 58 - I. 翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。



示例 1：

输入: "the sky is blue"
输出: "blue is sky the"

示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。



说明：

    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        /* 反转字符串 */
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0)
                    s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    Solution slt;
    cout << slt.reverseWords(s) << endl;
    return 0;
}
