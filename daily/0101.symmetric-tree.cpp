/* 101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。



示例 1：


输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：


输入：root = [1,2,2,null,3,null,3]
输出：false


提示：

树中节点数目在范围 [1, 1000] 内
-100 <= Node.val <= 100


进阶：你可以运用递归和迭代两种方法解决这个问题吗？ */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

    bool check_bfs(TreeNode *left, TreeNode *right)
    {
        queue<TreeNode *> q;
        q.push(left);
        q.push(right);
        while (!q.empty())
        {
            left = q.front();
            q.pop();

            right = q.front();
            q.pop();

            if (!right && !left)
                continue;
            if ((!right || !left) || (left->val != right->val))
                return false;

            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
    bool isSymmetric_bfs(TreeNode *root)
    {
        return check_bfs(root, root);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
