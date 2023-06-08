/* 2287. 重排字符形成目标字符串
给你两个下标从 0 开始的字符串 s 和 target 。你可以从 s 取出一些字符并将其重排，得到若干新的字符串。

从 s 中取出字符并重新排列，返回可以形成 target 的 最大 副本数。



示例 1：

输入：s = "ilovecodingonleetcode", target = "code"
输出：2
解释：
对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
可以形成最多 2 个 "code" 的副本，所以返回 2 。
示例 2：

输入：s = "abcba", target = "abc"
输出：1
解释：
选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。
可以形成最多 1 个 "abc" 的副本，所以返回 1 。
注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
示例 3：

输入：s = "abbaccaddaeea", target = "aaaaa"
输出：1
解释：
选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。


提示：

1 <= s.length <= 100
1 <= target.length <= 10
s 和 target 由小写英文字母组成 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        int count[26] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }

        int ans = 0;
        while (true)
        {
            for (int i = 0; i < target.size(); i++)
            {
                if (--count[target[i] - 'a'] < 0)
                    return ans;
            }
            ans++;
        }
    }

    int rearrangeCharacters_hashmap(string s, string target)
    {
        unordered_map<char, int> s_count, target_count;
        int s_size = s.size(), target_size = target.size();
        /* 将目标字符串的字母频次记录到哈希表 */
        for (int i = 0; i < target_size; i++)
        {
            target_count[target[i]]++;
        }
        /* 遍历搜索字符串，寻找目标字符串中出现的字母，记录到哈希表 */
        for (int i = 0; i < s_size; i++)
        {
            if (target_count.count(s[i]))
            {
                s_count[s[i]]++;
            }
        }
        int ans = INT_MAX;
        /* [c, count] => {key: <char> target_count[0], value: <int> target_count[1]} */
        for (auto [c, count] : target_count)
        {
            /* 搜索字符串中的目标字母个数 total_count*/
            int total_count = s_count[c];

            ans = min(ans, total_count / count);
            if (ans == 0)
            {
                return 0;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s, target;
    cin >> s >> target;
    Solution slt;
    cout << slt.rearrangeCharacters(s, target) << endl;
    return 0;
}
