/* 206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]


提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000


进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 **/
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
    ListNode *reverseList_stack(ListNode *head)
    {
        stack<ListNode *> s;
        ListNode *p = head;
        while (p)
        {
            s.push(p);
            p = p->next;
        }

        ListNode *new_list = new ListNode(0);
        ListNode *ans = new_list;
        while (!s.empty())
        {
            new_list->next = s.top();
            s.top()->next = nullptr;
            new_list = new_list->next;
            s.pop();
        }

        return ans->next;
    }
    ListNode *reverseList_straight(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = nullptr;

        while (cur)
        {
            ListNode *next = cur->next; /* 保存下一个结点,防止断链后无法访问 */
            cur->next = prev;           /* 断链 */
            prev = cur;                 /* 即将被指向的结点 */
            cur = next;                 /*下一个需要入链头的结点 */
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
