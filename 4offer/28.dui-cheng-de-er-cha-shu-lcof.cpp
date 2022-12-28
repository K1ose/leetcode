/* 剑指 Offer 28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3



示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false


限制：

0 <= 节点个数 <= 1000

注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ */
#include <iostream>
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
    bool check_dfs(TreeNode *left, TreeNode *right)
    {
        /* 如果两个子树结点都不存在，则返回 true */
        if (!left && !right)
            return true;
        /* 如果两个子树结点一个存在另一个不存在，则返回 false */
        if (!left || !right)
            return false;
        /* 满足对称的条件是：
        1. 根节点值相等；
        2. 根结点的左子树和右子树镜像对称 */
        return left->val == right->val && check_dfs(left->left, right->right) && check_dfs(left->right, right->left);
    }

    bool isSymmetric_dfs(TreeNode *root)
    {
        return check_dfs(root, root);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
