/* 剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。



示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."


限制：

0 <= s 的长度 <= 10000 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpaces(string s)
    {
        string ans;
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            if (s[i] == ' ')
                ans += "%20";
            else
                ans += s[i];
        }
        return ans;
    }

    string replaceSpace(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                s.replace(i, 1, "%20");
        }
        return s;
    }

    /* 不用replace()函数 */
    string replaceSpace_without_library_func(string s)
    {
        int count = 0; // 统计空格的个数
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 从后先前将空格替换为"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    Solution slt;
    cout << slt.replaceSpace(s);
    return 0;
}
