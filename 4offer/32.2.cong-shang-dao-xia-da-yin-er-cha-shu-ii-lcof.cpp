/* 剑指 Offer 32 - II. 从上到下打印二叉树 II
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。



例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


提示：

节点总数 <= 1000 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {
                int cur_size = q.size(); /* 记录队列数量，当前层级的结点数量 */
                vector<int> level;

                /* 遍历获取当前层级上的结点，将它们逐一出队，逐一加入孩子结点 */
                for (int i = 0; i < cur_size; i++)
                {
                    TreeNode *cur_node = q.front();
                    q.pop();
                    level.push_back(cur_node->val);

                    if (cur_node->left)
                        q.push(cur_node->left);
                    if (cur_node->right)
                        q.push(cur_node->right);
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};