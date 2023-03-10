/* 21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。



示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]


提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列 */

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *ans = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                head->next = list1;
                head = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }
        if (list1)
        {
            head->next = list1;
        }
        if (list2)
        {
            head->next = list2;
        }
        return ans->next;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
