/* 102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。



示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]


提示：

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000 */

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
                int cur_size = q.size();      /* 记录队列数量，当前层级的结点数量 */
                ans.push_back(vector<int>()); /* 加入一行数组 */

                /* 遍历获取当前层级上的结点，将它们逐一出队，逐一加入孩子结点 */
                for (int i = 0; i < cur_size; i++)
                {
                    TreeNode *cur_node = q.front();
                    q.pop();
                    ans.back().push_back(cur_node->val);

                    if (cur_node->left)
                        q.push(cur_node->left);
                    if (cur_node->right)
                        q.push(cur_node->right);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
