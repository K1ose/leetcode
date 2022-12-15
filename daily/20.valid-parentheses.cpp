/* 20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false


提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> S;
        int size = s.size();
        if (size % 2 == 1)
            return false;

        unordered_map<char, char> pairs = {
            {'}', '{'},
            {')', '('},
            {']', '['}};

        for (char c : s)
        {
            if (pairs.count(c)) // 如果符号是pairs中的元素，即： }, ), ]
            {
                /* 如果栈空，或者栈顶元素不匹配，则返回 false */
                if (S.empty() || S.top() != pairs[c])
                    return false;
                S.pop();
            }
            else /* 否则把符号压入栈 */
                S.push(c);
        }
        return S.empty();
    }

    /* JAVA 和 python 的巧妙做法：由于只包含括号，所以可以这么做 */
    /* bool is_vaild(string str)
    {
        while (true)
        {
            int l = str.length();
            str = str.replace("()", "");
            str = str.replace("{}", "");
            str = str.replace("[]", "");
            if (str.length() == l)
            {
                return l == 0;
            }
        }
    } */
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    Solution slt;
    cout << slt.isValid(s);
    return 0;
}
