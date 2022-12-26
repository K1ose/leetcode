/* 1759. 统计同构子字符串的数目
给你一个字符串 s ，返回 s 中 同构子字符串 的数目。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。

同构字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。

子字符串 是字符串中的一个连续字符序列。



示例 1：

输入：s = "abbcccaa"
输出：13
解释：同构子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
示例 2：

输入：s = "xy"
输出：2
解释：同构子字符串是 "x" 和 "y" 。
示例 3：

输入：s = "zzzzz"
输出：15


提示：

1 <= s.length <= 105
s 由小写字符串组成 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countHomogenous_mine(string s)
    {
        int len = s.size();
        unordered_map<string, int> count;
        int i = 0, j;
        while (i < len)
        {
            j = i + 1;
            while (j <= len && s[i] == s[j])
                j++;
            string str = s.substr(i, j - i);
            count[str]++;
            i = j;
        }

        long long sum = 0;
        long long mod = 1e9 + 7;
        long long cur = 0;
        for (auto x : count)
        {
            int size = x.first.size();
            cur = (long long)(size + 1) * size / 2;
            sum += cur * x.second;
        }
        return sum % mod;
    }

    int countHomogenous(string s)
    {
        long long res = 0;
        long long mod = 1e9 + 7;
        int prev = s[0];
        int cnt = 0;
        for (auto c : s)
        {
            if (c == prev)
            {
                cnt++;
            }
            else
            {
                res += (long long)(cnt + 1) * cnt / 2;
                cnt = 1;
                prev = c;
            }
        }
        res += (long long)(cnt + 1) * cnt / 2;
        return res % mod;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    Solution slt;
    cout << slt.countHomogenous(s) << endl;
    ;
    return 0;
}
