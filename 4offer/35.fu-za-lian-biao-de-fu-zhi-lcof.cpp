/* 剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。



示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：

输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：

输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。



提示：

    -10000 <= Node.val <= 10000
    Node.random 为空（null）或指向链表中的节点。
    节点数目不超过 1000 。
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        /* 如果链表为空，则返回NULL */
        if (head == nullptr)
        {
            return nullptr;
        }

        /* 在原链表的每个节点后插入一个相同的节点 */
        /* 对next指针进行复制 */
        for (Node *p = head; p != nullptr; p = p->next->next)
        {
            Node *insNode = new Node(p->val); /* 创建一个新节点，值为p->val */

            /* 将其插入到原节点后面 */
            insNode->next = p->next;
            p->next = insNode;
        }
        /* 对random指针进行复制 */
        for (Node *p = head; p != nullptr; p = p->next->next)
        {
            Node *insNode = p->next; /* 对应原节点p的复制节点 */

            /* 设置random指针的指向，通过next指针来找到对应原节点p的复制节点insNode */
            if (p->random != nullptr)
            {
                insNode->random = p->random->next;
            }
            else
            {
                insNode->random = nullptr;
            }
        }

        /* 分离原节点和复制节点 */
        Node *new_head = head->next;
        for (Node *p = head; p != nullptr; p = p->next)
        {
            Node *insNode = p->next; /* 指向每一个复制节点 */
            p->next = p->next->next; /* 原节点的next指向复制节点的next，即越过复制节点，连接原节点 */

            if (insNode->next != nullptr)
            {
                /* 指向复制节点 */
                insNode->next = insNode->next->next;
            }
            else
            {
                insNode->next = nullptr;
            }
        }
        return new_head;
    }
};