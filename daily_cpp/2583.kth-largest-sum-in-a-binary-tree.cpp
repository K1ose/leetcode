/* 2583. Kth Largest Sum in a Binary Tree
中等
相关标签
相关企业
提示
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.



Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.


Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n */
#include "../tools/program_head.h"
#include "../tools/display.h"
#include "../tools/struct.h"
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
private:
    vector<int> sum;
    long long height = 0;

public:
    void dfs(TreeNode *root, long long height)
    {
        if (!root)
        {
            return;
        }
        if (sum[height])
        {
            sum[height] += root->val;
        }
        else
        {
            sum.push_back(root->val);
        }
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        dfs(root, height);
        sort(sum.begin(), sum.end());
        return sum[k - 1];
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
