/* 83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。



示例 1：


输入：head = [1,1,2]
输出：[1,2]
示例 2：


输入：head = [1,1,2,3,3]
输出：[1,2,3]


提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列 */

/**
  Definition for singly-linked list.
  **/
#include <iostream>
#include <set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /* 没看到题目说的是升序链表。。。 */
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pre = new ListNode(0, head);
        ListNode *cur = pre->next;

        set<int> count;

        while (cur)
        {

            if (count.count(cur->val))
                pre->next = cur->next;
            else
            {
                count.emplace(cur->val);
                pre = pre->next;
            }
            cur = pre->next;
        }

        return head;
    }
};