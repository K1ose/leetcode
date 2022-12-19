/* 剑指 Offer 32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。



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
  [20,9],
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
            bool left_order = true;
            q.push(root);

            while (!q.empty())
            {
                int cur_size = q.size(); /* 记录队列数量，当前层级的结点数量 */
                deque<int> dq;           /* 双向队列 */

                /* 遍历获取当前层级上的结点，将它们逐一出队，逐一加入孩子结点 */
                for (int i = 1; i <= cur_size; i++)
                {
                    TreeNode *cur_node = q.front();
                    q.pop();
                    if (left_order)
                        dq.push_back(cur_node->val);
                    else
                        dq.push_front(cur_node->val);

                    /* 先左后右的遍历顺序没有变，需要变的只是输出的顺序 */
                    if (cur_node->left)
                        q.push(cur_node->left);
                    if (cur_node->right)
                        q.push(cur_node->right);
                }
                /* 将当前层遍历元素集合 dp 放到返回数组中*/
                ans.emplace_back(vector<int>{dq.begin(), dq.end()});
                left_order = !left_order;
            }
        }
        return ans;
    }
};