/* 2476. Closest Nodes Queries in a Binary Search Tree
中等
相关标签
相关企业
提示
You are given the root of a binary search tree and an array queries of size n consisting of positive integers.

Find a 2D array answer of size n where answer[i] = [mini, maxi]:

mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
Return the array answer.



Example 1:


Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
Output: [[2,2],[4,6],[15,-1]]
Explanation: We answer the queries in the following way:
- The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
- The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
- The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].
Example 2:


Input: root = [4,null,9], queries = [3]
Output: [[-1,4]]
Explanation: The largest number that is smaller or equal to 3 in the tree does not exist, and the smallest number that is greater or equal to 3 is 4. So the answer for the query is [-1,4].


Constraints:

The number of nodes in the tree is in the range [2, 105].
1 <= Node.val <= 106
n == queries.length
1 <= n <= 105
1 <= queries[i] <= 106 */
#include "../tools/program_head.h"
#include "../tools/display.h"
#include "../tools/struct.h"
#include "../tools/build.h"
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
    vector<int> a;

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        dfs(node->left);
        a.push_back(node->val);
        dfs(node->right);
    };

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        dfs(root);
        int n = a.size();
        vector<vector<int>> ans;
        for (int q : queries)
        {
            // j 为 ceil 在 sort_arr 中的下标
            int j = ranges::lower_bound(a, q) - a.begin();
            int mx = j < n ? a[j] : -1;

            if (j == n || a[j] != q)
            { // a[j]>q, a[j-1]<q
                j--;
            }
            int mn = j >= 0 ? a[j] : -1;
            ans.push_back({mn, mx});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {6, 2, 13, 1, 4, 9, 15, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 14};
    vector<int> queries = {2, 5, 16};
    TreeNode *root = buildTree(nums);
    Solution slt;
    print_vec2d_matrix(slt.closestNodes(root, queries));
    return 0;
}
