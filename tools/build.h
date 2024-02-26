#pragma once
#include "../tools/struct.h"
#include <iostream>
using namespace std;

template <typename T>
TreeNode *buildTree(vector<T> nums)
{
    if (nums.empty())
        return nullptr;

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(nums[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nums.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (i < nums.size() && nums[i] != INT_MIN)
        {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;

        if (i < nums.size() && nums[i] != INT_MIN)
        {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}
