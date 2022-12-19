/* 剑指 Offer 32 - I. 从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。



例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]


提示：

节点总数 <= 1000 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.

 */
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
    /* binary tree BFS */
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;  /* 存放结点的队列 */
        vector<int> node_val; /* 存放遍历结点的值 */

        if (root) /* 如果根结点存在 */
        {
            q.push(root);      /* 根结点入队 */
            while (!q.empty()) /* 只要队列不为空 */
            {
                /* 将当前双亲节点的 val 域添加到 node_val */
                node_val.push_back(q.front()->val);

                /* 如果该结点有左右孩子，将左右孩子结点按先左后右顺序入队 */
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);

                /* 将当前的双亲结点出队 */
                q.pop();
            }
        }
        return node_val;
    }
};