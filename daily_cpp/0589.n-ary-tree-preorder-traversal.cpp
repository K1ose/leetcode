/* 589. N-ary Tree Preorder Traversal
简单

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)



Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]


Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.


Follow up: Recursive solution is trivial, could you do it iteratively? */

#include "../tools/display.h"
#include "../tools/program_head.h"
#include "../tools/struct.h"
using namespace std;

class Solution
{
public:
    vector<int> ans;
    void dfs(Node *node)
    {
        if (node)
        {
            ans.push_back(node->val);
            if (node->children.size() > 0)
            {
                for (auto x : node->children)
                {
                    dfs(x);
                }
            }
        }
    }

    vector<int> preorder(Node *root)
    {
        dfs(root);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Node *leaf1 = new Node(5);
    Node *leaf2 = new Node(6);
    vector<Node *> c2 = {leaf1, leaf2};
    Node *leaf3 = new Node(2);
    Node *leaf4 = new Node(4);
    Node *node1 = new Node(3, c2);
    vector<Node *> c1 = {node1, leaf3, leaf4};
    Node *root = new Node(1, c1);

    Solution slt;
    print_vec1d_arr(slt.preorder(root));
    return 0;
}
