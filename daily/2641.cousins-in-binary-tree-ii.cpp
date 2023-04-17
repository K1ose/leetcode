/* 2641. 二叉树的堂兄弟节点 II

给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。

如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。

请你返回修改值之后，树的根 root 。

注意，一个节点的深度指的是从树根节点到这个节点经过的边数。



示例 1：

输入：root = [5,4,9,1,10,null,7]
输出：[0,0,0,7,7,null,11]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。

示例 2：

输入：root = [3,1,2]
输出：[0,0,0]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
- 值为 2 的节点没有堂兄弟，所以值修改为 0 。



提示：

    树中节点数目的范围是 [1, 105] 。
    1 <= Node.val <= 104

 */
#include "../tools/display.h"
#include "../tools/program_head.h"
#include "../tools/struct.h"
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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        /* 下一层的节点队列，用于计算同一层的所有节点的val和 */
        queue<TreeNode *> TreeQueue;
        TreeQueue.push(root);
        root->val = 0;
        while (!TreeQueue.empty())
        {
            queue<TreeNode *> cur_level_nodes; /* 当前层的节点队列，用于修改该层每一个节点的值为 当前层所有节点val和 减去 当前节点的孩子val和 */
            int TQsize = TreeQueue.size();

            /* 计算下一层所有节点的val和，存储到next_level_sum中 */
            int next_level_sum = 0;
            for (int i = 0; i < TQsize; i++)
            {
                TreeNode *cur_node = TreeQueue.front();
                if (cur_node->left)
                {
                    TreeQueue.push(cur_node->left);
                    next_level_sum += cur_node->left->val;
                }
                if (cur_node->right)
                {
                    TreeQueue.push(cur_node->right);
                    next_level_sum += cur_node->right->val;
                }
                cur_level_nodes.push(cur_node);
                TreeQueue.pop();
            }

            /* 修改当前节点的孩子的值为next_level_sum-(childrem_sum) */
            int NL_size = cur_level_nodes.size();
            for (int i = 0; i < NL_size; i++)
            {
                TreeNode *cur_node = cur_level_nodes.front();
                int children_sum = (cur_node->left ? cur_node->left->val : 0) + (cur_node->right ? cur_node->right->val : 0);
                if (cur_node->left)
                {
                    cur_node->left->val = next_level_sum - children_sum;
                }
                if (cur_node->right)
                {
                    cur_node->right->val = next_level_sum - children_sum;
                }
                cur_level_nodes.pop();
            }
        }
        return root;
    }
};