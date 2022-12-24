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
    TreeNode *mirrorTree(TreeNode *root)
    {
        // TODO
        queue<TreeNode *> q;
        vector<int> ans;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {

                if (q.front()->right && q.front()->left)
                {
                    int temp = q.front()->right->val;
                    q.front()->right->val = q.front()->left->val;
                    q.front()->left->val = temp;
                }

                else if (q.front()->right)
                {
                    q.front()->left = q.front()->right;
                    q.front()->right = nullptr;
                }
                else if (q.front()->left)
                {
                    q.front()->right = q.front()->left;
                    q.front()->left = nullptr;
                }
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
