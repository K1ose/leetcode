/* 剑指 Offer 54. 二叉搜索树的第k大节点

给定一棵二叉搜索树，请找出其中第 k 大的节点的值。



示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4

示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4



限制：

    1 ≤ k ≤ 二叉搜索树元素个数

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "../tools/display.h"
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
    /* 写的时候没有看到这是一颗搜索树，所以直接全部遍历了一遍。如果是搜索树，就直接先遍历右子树，访问根节点后遍历左子树，找到第k个节点即可 */
    vector<int> res;
    int max_kth;
    void dfs_normal_tree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        dfs_normal_tree(root->left);
        dfs_normal_tree(root->right);
        res.push_back(root->val);
    }
    /* 注意这里要用 &k 进行引用 */
    void dfs(TreeNode *root, int &k)
    {
        if (k <= 0 || !root)
        {
            return;
        }
        dfs(root->right, k);
        --k;
        if (k == 0)
        {
            max_kth = root->val;
            return;
        }
        dfs(root->left, k);
    }

    int kthLargest(TreeNode *root, int k)
    {
        // dfs_normal_tree(root);
        dfs(root, k);
        // sort(res.begin(), res.end());
        return res[res.size() - k];
    }
};
