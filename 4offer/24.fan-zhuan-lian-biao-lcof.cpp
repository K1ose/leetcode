/* 剑指 Offer 24. 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。



示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL



限制：

0 <= 节点个数 <= 5000 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /*
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    */
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *h = new ListNode(0);
        h->next = head;

        ListNode *cur = head;
        ListNode *auxiliary;
        while (cur)
        {
            auxiliary = cur->next;
            cur->next = h->next;
            h->next = cur;
            cur = auxiliary;
        }
        head->next = nullptr;
        return h->next;
    }
};
