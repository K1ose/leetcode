/* 106. Construct Binary Tree from Inorder and Postorder Traversal
中等
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree. */
#include "../tools/program_head.h"
#include "../tools/display.h"
#include "../tools/struct.h"
using namespace std;

class Solution
{
private:
    unordered_map<int, int> inorder_index;
    int postorder_idx;

public:
    TreeNode *recursion(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right)
    {
        if (inorder_left > inorder_right || postorder_idx < 0)
        {
            return nullptr;
        }

        int inorder_root_idx = inorder_index[postorder[postorder_idx]]; // 当前根节点在 中序遍历数组 中的位置下标

        TreeNode *root = new TreeNode(postorder[postorder_idx]); // 构造当前根节点

        postorder_idx--;
        // 递归右子树
        root->right = recursion(inorder, postorder, inorder_root_idx + 1, inorder_right);
        // 递归左子树
        root->left = recursion(inorder, postorder, inorder_left, inorder_root_idx - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        postorder_idx = n - 1;
        for (int i = 0; i < n; i++)
        {
            inorder_index[inorder[i]] = i;
        }
        return recursion(inorder, postorder, 0, n - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> inorder = {4, 5, 8, 10, 9, 2, 3, 15, 20, 7};
    vector<int> postorder = {4, 5, 10, 8, 2, 9, 15, 7, 20, 3};
    Solution slt;
    TreeNode *root = slt.buildTree(inorder, postorder);
    print_tree(root);
    return 0;
}
