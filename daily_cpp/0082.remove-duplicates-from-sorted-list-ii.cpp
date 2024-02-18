/* 82. 删除排序链表中的重复元素 II
中等
相关标签
相关企业
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。



示例 1：


输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：


输入：head = [1,1,1,2,3]
输出：[2,3]


提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列
 */
#include "../tools/program_head.h"
#include "../tools/struct.h"
#include "../tools/display.h"
using namespace std;

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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head)
        {
            ListNode *pre = head;
            ListNode *p = pre->next;
            ListNode *auxilary = new ListNode(0, head);
            while (p)
            {
                if (pre->val != p->val)
                {
                    pre = p;
                    auxilary = auxilary->next;
                    p = p->next;
                }
                else
                {
                    while (p && pre->val == p->val)
                    {
                        p = p->next;
                    }
                    if (auxilary->next == head)
                    {
                        head = p;
                    }
                    pre = p;
                    if (p)
                    {
                        p = p->next;
                    }
                    auxilary->next = pre;
                }
            }
            return head;
        }
        else
        {
            return nullptr;
        }
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode();
    ListNode *p = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *new_node = new ListNode(x);
        p->next = new_node;
        p = p->next;
    }

    Solution slt;
    ListNode *new_head = slt.deleteDuplicates(head->next);
    print_linklist(new_head);
    return 0;
}
