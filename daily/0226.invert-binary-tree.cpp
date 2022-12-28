/* 226. 翻转二叉树
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。



示例 1：



输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
示例 2：



输入：root = [2,1,3]
输出：[2,3,1]
示例 3：

输入：root = []
输出：[]


提示：

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 **/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void dfs(TreeNode *node)
    {
        if (!node)
            return;

        /* 交换左右两个结点 */
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;

        /* 递归调用，交换剩下的结点 */
        dfs(node->left);
        dfs(node->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        dfs(root);
        return root;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
