/* 剑指 Offer 27. 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1



示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]


限制：

0 <= 节点个数 <= 1000

 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void dfs(TreeNode *node)
    {
        if (!node)
            return;

        TreeNode *temp_node = node->left;
        node->left = node->right;
        node->right = temp_node;

        dfs(node->left);
        dfs(node->right);
    }
    TreeNode *mirrorTree(TreeNode *root)
    {
        dfs(root);
        return root;
    }

    /* other */
    /*
    特殊判断：空树的镜像翻转树仍然是本身
    思路：翻转左子树后替换右子树，翻转右子树后替换左子树
    */
    TreeNode *mirrorTree2(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        TreeNode *left = mirrorTree2(root->left);
        TreeNode *right = mirrorTree2(root->right);
        left = root->left;
        right = root->right;
        return root;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
