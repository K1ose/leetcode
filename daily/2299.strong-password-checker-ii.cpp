/* 2299. 强密码检验器 II
如果一个密码满足以下所有条件，我们称它是一个 强 密码：

它有至少 8 个字符。
至少包含 一个小写英文 字母。
至少包含 一个大写英文 字母。
至少包含 一个数字 。
至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。



示例 1：

输入：password = "IloveLe3tcode!"
输出：true
解释：密码满足所有的要求，所以我们返回 true 。
示例 2：

输入：password = "Me+You--IsMyDream"
输出：false
解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
示例 3：

输入：password = "1aB!"
输出：false
解释：密码不符合长度要求。所以我们返回 false 。


提示：

1 <= password.length <= 100
password 包含字母，数字和 "!@#$%^&*()-+" 这些特殊字符。 */
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        int len = password.size();
        if (len < 8)
        {
            return false;
        }
        set<char> symbol_list = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        bool upper_letter = false, lower_letter = false;
        bool num = false;
        bool symbol = false;
        for (int i = 0; i < password.size(); i++)
        {
            if (i < len - 1 && password[i] == password[i + 1])
            {
                return false;
            }
            if (lower_letter == false && password[i] >= 'a' && password[i] <= 'z')
            {
                lower_letter = true;
            }
            if (upper_letter == false && password[i] >= 'A' && password[i] <= 'Z')
            {
                upper_letter = true;
            }
            if (num == false && password[i] >= '0' && password[i] <= '9')
            {
                num = true;
            }
            if (symbol == false && (symbol_list.count(password[i]) > 0))
            {
                symbol = true;
            }
        }

        if (lower_letter && upper_letter && num && symbol)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string pw;
    cin >> pw;
    Solution slt;
    cout << slt.strongPasswordCheckerII(pw) << endl;
    return 0;
}
