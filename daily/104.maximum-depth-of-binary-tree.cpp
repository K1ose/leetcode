/* 104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。 */

#include <iostream>
#include <vector>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth_bfs(TreeNode *root)
    {

        if (!root)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int cur_size = q.size();
            for (int i = 0; i < cur_size; i++)
            {
                TreeNode *cur_node = q.front();
                q.pop();
                if (cur_node->left)
                    q.push(cur_node->left);
                if (cur_node->right)
                    q.push(cur_node->right);
            }
            depth++;
        }
        return depth;
    }

    int maxDepth_dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return max(maxDepth_dfs(root->left), maxDepth_dfs(root->right)) + 1;
    }

    // 更直观
    int getdepth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = 1 + max(leftdepth, rightdepth);
        return depth;
    }
    int maxdepth(TreeNode *root)
    {
        return getdepth(root);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
