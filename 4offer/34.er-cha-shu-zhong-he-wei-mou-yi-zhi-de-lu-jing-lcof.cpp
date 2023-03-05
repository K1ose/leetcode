/* 剑指 Offer 34. 二叉树中和为某一值的路径

给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。



示例 1：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：

输入：root = [1,2,3], targetSum = 5
输出：[]

示例 3：

输入：root = [1,2], targetSum = 0
输出：[]



提示：

    树中节点总数在范围 [0, 5000] 内
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000

注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/
 */

#include <iostream>
#include <vector>
#include "../tools/display.h"
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
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode *root, int target)
    {
        if (!root)
        {
            return;
        }

        /* 将当前节点的值添加到当前路径数组中 */
        path.emplace_back(root->val);
        target -= root->val;
        /* 如果符合题目要求，则将该路径添加如返回二维数组中 */
        if (!root->left && !root->right && target == 0)
        {
            ret.emplace_back(path);
        }
        dfs(root->left, target);
        dfs(root->right, target);

        /* 清空当前路径数组 */
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        dfs(root, target);
        return ret;
    }
};