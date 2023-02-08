/* 1233. 删除子文件夹
你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的 子文件夹 。

文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：'/' 后跟一个或者多个小写英文字母。

例如，"/leetcode" 和 "/leetcode/problems" 都是有效的路径，而空字符串和 "/" 不是。


示例 1：

输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
输出：["/a","/c/d","/c/f"]
解释："/a/b/" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
示例 2：

输入：folder = ["/a","/a/b/c","/a/b/d"]
输出：["/a"]
解释：文件夹 "/a/b/c" 和 "/a/b/d/" 都会被删除，因为它们都是 "/a" 的子文件夹。
示例 3：

输入: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
输出: ["/a/b/c","/a/b/ca","/a/b/d"]


提示：

1 <= folder.length <= 4 * 104
2 <= folder[i].length <= 100
folder[i] 只包含小写字母和 '/'
folder[i] 总是以字符 '/' 起始
每个文件夹名都是 唯一 的 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include "tool.h"
#include <string>
#include <functional>
using namespace std;

struct DictTree
{
    unordered_map<string, DictTree *> children;
    int ref;
    DictTree()
    {
        ref = -1;
    }
};

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        /* lambda 表达式 */
        auto split = [](const string &s) -> vector<string>
        {
            vector<string> ret;
            string cur;
            for (char c : s)
            {
                if (c == '/')
                {
                    ret.push_back(move(cur));
                    cur.clear();
                }
                else
                {
                    cur.push_back(c);
                }
            }
            ret.push_back(move(cur));
            return ret;
        };

        DictTree *root = new DictTree();
        for (int i = 0; i < folder.size(); i++)
        {
            vector<string> path = split(folder[i]);
            // print_vector_arr(path);
            DictTree *cur = root;
            for (auto dirname : path)
            {
                if (!cur->children.count(dirname))
                {
                    cur->children[dirname] = new DictTree();
                }
                cur = cur->children[dirname];
            }
            cur->ref = i;
        }

        vector<string> ans;
        function<void(DictTree *)> dfs = [&](DictTree *cur)
        {
            if (cur->ref != -1)
            {
                ans.push_back(folder[cur->ref]);
                return;
            }
            for (auto &&[_, child] : cur->children)
            {
                dfs(child);
            }
        };

        dfs(root);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> folder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> folder[i];
    }
    Solution slt;
    slt.removeSubfolders(folder);
    return 0;
}
