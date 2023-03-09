/* 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。



说明:

    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。

注意：本题与主站 235 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
#include "../tools/program_head.h"
#include "../tools/struct.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        /* 利用二叉搜索树的性质，左子树的节点的值都小于根节点的值，右子树的节点的值都大于根节点的值。因此，在寻找p和q的公共祖先时，如果遍历的当前节点cur_node：
        1. cur_node->val > p->val, cur_node->val > q->val，即 当前节点值比两个节点的值都要大，说明他们的公共祖先在当前节点的左子树;
        2. cur_node->val < p->val, cur_node->val < q->val，即 当前节点值比两个节点的值都要小，说明他们的公共祖先在当前节点的右子树;
        3. 如果不满足上述条件，那么p、q要么分别于当前节点的左右子树中，要么有一个为当前节点，即找到公共祖先。
        */
        TreeNode *cur_node = root;
        while (true)
        {
            if (cur_node->val > p->val && cur_node->val > q->val)
            {
                cur_node = cur_node->left;
            }
            else if (cur_node->val < p->val && cur_node->val < q->val)
            {
                cur_node = cur_node->right;
            }
            else
            {
                break;
            }
        }
        return cur_node;
    }
};
