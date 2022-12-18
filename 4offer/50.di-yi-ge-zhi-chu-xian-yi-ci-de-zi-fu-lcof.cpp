/* 剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例 1:

输入：s = "abaccdeff"
输出：'b'
示例 2:

输入：s = ""
输出：' '


限制：

0 <= s 的长度 <= 50000
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, int> map;
        int len = s.size();
        for (int i = 0; i < len; i++)
            map[s[i]]++;
        for (int i = 0; i < len; i++)
        {
            if (map[s[i]] == 1)
                return s[i];
        }
        return ' ';
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    Solution slt;
    cout << slt.firstUniqChar(s) << endl;
    return 0;
}
