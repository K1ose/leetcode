/* 1457. 二叉树中的伪回文路径
中等
相关标签
相关企业
提示
给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。



示例 1：



输入：root = [2,3,1,3,1,null,1]
输出：2
解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
示例 2：



输入：root = [2,1,1,1,3,null,null,null,null,null,1]
输出：1
解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
示例 3：

输入：root = [9]
输出：1


提示：

给定二叉树的节点数目在范围 [1, 105] 内
1 <= Node.val <= 9 */
#include "../tools/program_head.h"
#include "../tools/display.h"
#include "../tools/struct.h"
#include "../tools/func.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isPseudoPalindrome(vector<int> cnter)
    {
        int odd = 0;
        for (int val : cnter)
        {
            if (val % 2 == 1)
            {
                odd++;
            }
        }
        return odd <= 1;
    }

    int dfs(TreeNode *root, vector<int> &cnter)
    {
        if (!root)
        {
            return 0;
        }
        cnter[root->val]++;
        int ans = 0;
        if (!root->left && !root->right)
        {
            if (isPseudoPalindrome(cnter))
            {
                ans++;
            }
        }
        else
        {
            ans = dfs(root->left, cnter) + dfs(root->right, cnter);
        }
        cnter[root->val]--;
        return ans;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> cnter(10, 0);
        return dfs(root, cnter);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node1_2 = new TreeNode(3, node1, node2);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node0_3 = new TreeNode(1, nullptr, node3);
    TreeNode *root = new TreeNode(2, node1_2, node0_3);

    Solution slt;
    cout << slt.pseudoPalindromicPaths(root) << endl;

    return 0;
}
