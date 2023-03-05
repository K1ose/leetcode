/* 剑指 Offer 36. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。



为了让您更好地理解问题，以下面的二叉搜索树为例：





我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。





特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。



注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。
 */

#include <iostream>
#include <vector>
#include "../tools/display.h"
#include "../tools/struct.h"
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    Node *pre, *head;

    void dfs(Node *root)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left);
        /* 判断是否为开头节点 */
        if (pre)
        {
            /* 如果不是头节点 */
            pre->right = root;
        }
        else
        {
            /* 如果是头节点 */
            head = root;
        }
        root->left = pre; /* 第一个节点的left将指向null，后续节点将指向前驱节点 */
        pre = root;
        dfs(root->right);
    }
    /* 二叉搜索树是中序递增的二叉树，利用中序遍历二叉数来获得val递增的节点，对节点进行链表化 */
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};