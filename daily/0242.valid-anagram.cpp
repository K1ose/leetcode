/* 242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母


进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int count[26] = {0};
        for (auto x : s)
            count[x - 'a']++;

        for (auto y : t)
            count[y - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;

    Solution slt;
    cout << slt.isAnagram(s, t) << endl;
    return 0;
}
