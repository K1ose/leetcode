/* 2744. 最大字符串配对数目
简单
相关标签
相关企业
提示
给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。

如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：

字符串 words[i] 等于 words[j] 的反转字符串。
0 <= i < j < words.length
请你返回数组 words 中的 最大 匹配数目。

注意，每个字符串最多匹配一次。



示例 1：

输入：words = ["cd","ac","dc","ca","zz"]
输出：2
解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
可以证明最多匹配数目是 2 。
示例 2：

输入：words = ["ab","ba","cc"]
输出：1
解释：在此示例中，我们可以通过以下方式匹配 1 对字符串：
- 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
可以证明最多匹配数目是 1 。
示例 3：

输入：words = ["aa","ab"]
输出：0
解释：这个例子中，无法匹配任何字符串。


提示：

1 <= words.length <= 50
words[i].length == 2
words 包含的字符串互不相同。
words[i] 只包含小写英文字母。 */

#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    /* 我们也可以借助哈希集合，只进行一次遍历。

    当我们枚举到 words[i] 时，我们将之前的所有字符串 words[0..i−1] 放入哈希集合中。如果 words[i] 的反转字符串在哈希集合中存在，那么匹配的数量增加 1。

    对于比较方便得到反转字符串的语言，我们可以在哈希集合中存储字符串本身；对于其它语言，我们可以存储字符串的哈希值，改为判断 words[i]的反转字符串的哈希值是否存在。哈希值需要保证不会冲突，本题中字符串的长度为 2 并且只包含小写字母，因此可以使用 100a+b 作为哈希值，其中 a 和 b 分别是两个字符的 ASCII 值。

 */
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;
        unordered_set<int> check_pair;
        for (int i = 0; i < n; ++i)
        {
            if (check_pair.count(words[i][1] * 100 + words[i][0]))
            {
                ++ans;
            }
            check_pair.insert(words[i][0] * 100 + words[i][1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
    Solution slt;
    cout << slt.maximumNumberOfStringPairs(words);
    return 0;
}
