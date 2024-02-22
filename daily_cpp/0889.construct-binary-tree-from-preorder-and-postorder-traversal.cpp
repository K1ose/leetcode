/* 889. Construct Binary Tree from Preorder and Postorder Traversal
中等
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.



Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]


Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
 */

#include "../tools/program_head.h"
#include "../tools/struct.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        unordered_map<int, int> postMap;
        for (int i = 0; i < n; i++)
        {
            postMap[postorder[i]] = i;
        }
        function<TreeNode *(int, int, int, int)> dfs = [&](int preLeft, int preRight, int postLeft, int postRight) -> TreeNode *
        {
            if (preLeft > preRight)
            {
                return nullptr;
            }
            int leftCount = 0;
            if (preLeft < preRight)
            {
                leftCount = postMap[preorder[preLeft + 1]] - postLeft + 1;
            }
            return new TreeNode(preorder[preLeft],
                                dfs(preLeft + 1, preLeft + leftCount, postLeft, postLeft + leftCount - 1),
                                dfs(preLeft + leftCount + 1, preRight, postLeft + leftCount, postRight - 1));
        };
        return dfs(0, n - 1, 0, n - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Solution slt;
    TreeNode *root = slt.constructFromPrePost(preorder, postorder);
    print_tree(root);
    return 0;
}
