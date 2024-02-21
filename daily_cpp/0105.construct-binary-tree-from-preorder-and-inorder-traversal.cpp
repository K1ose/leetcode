/* 105. Construct Binary Tree from Preorder and Inorder Traversal
中等

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree. */

#include "../tools/program_head.h"
#include "../tools/display.h"
#include "../tools/struct.h"
using namespace std;

class Solution
{
private:
    unordered_map<int, int> in_index;

public:
    TreeNode *recursion(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {

        if (pre_left > pre_right || pre_left >= preorder.size())
        {
            return nullptr;
        }

        int in_root = in_index[preorder[pre_left]]; // 通过当前子树根节点的值找到其在中序遍历中的位置下标

        TreeNode *root = new TreeNode(preorder[pre_left]); // 建立当前根节点
        int left_tree_cnt = in_root - in_left;             // 当前根节点左子树节点数量

        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = recursion(preorder, inorder, pre_left + 1, pre_left + left_tree_cnt, in_left, in_root - 1);

        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = recursion(preorder, inorder, pre_left + 1 + left_tree_cnt, pre_right, in_root + 1, in_right);

        // 返回根节点
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            in_index[inorder[i]] = i;
        }
        return recursion(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> preorder = {3, 9, 8, 5, 4, 10, 20, 15, 7};
    vector<int> inorder = {4, 5, 8, 10, 9, 3, 15, 20, 7};
    Solution slt;
    TreeNode *root = slt.buildTree(preorder, inorder);
    print_tree(root);
    return 0;
}
