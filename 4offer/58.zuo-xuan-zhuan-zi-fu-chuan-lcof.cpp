/* 剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。



示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"


限制：

1 <= k < s.length <= 10000
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        /* 反转n前面的字符串 */
        reverse(s.begin(), s.begin() + n);
        /* 反转n后面的字符串 */
        reverse(s.begin() + n, s.end());
        /* 反转整个字符串 */
        reverse(s.begin(), s.end());

        return s;
    }

    /* 拼接 */
    string reverseLeftWords_combine(string str, int n)
    {
        int len = str.size();
        if (len == 0)
            return str;
        string s = str.substr(0, n);
        string ans = str.substr(n, len - n) + s;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> s >> n;
    Solution slt;
    cout << slt.reverseLeftWords(s, n);
    return 0;
}
