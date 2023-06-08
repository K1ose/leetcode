/* 24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。



示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1] */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p = head;
        int order = 0;
        if (!head)
        {
            return nullptr;
        }

        if (p && !p->next)
        {
            return p;
        }

        while (p && p->next)
        {
            int temp = p->next->val;
            p->next->val = p->val;
            p->val = temp;
            p = p->next->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
