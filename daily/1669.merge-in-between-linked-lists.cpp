/* 1669. 合并两个链表
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

下图中蓝色边和节点展示了操作后的结果：


请你返回结果链表的头指针。



示例 1：



输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
输出：[0,1,2,1000000,1000001,1000002,5]
解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
示例 2：


输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
解释：上图中蓝色的边和节点为答案链表。


提示：

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104 */

#include <iostream>
#include <vector>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 头插法 */
ListNode *insert_node_head(int n)
{
    int element;

    cin >> element;
    n--;
    ListNode *list = new ListNode(element);

    while (n--)
    {
        cin >> element;
        ListNode *new_node = new ListNode(element, list->next);
        list->next = new_node;
    }
    return list;
}

/* 尾插法 */
ListNode *insert_node_tail(int n)
{
    int element;
    cin >> element;
    n--;
    ListNode *list = new ListNode(element);
    ListNode *head = list;
    while (n--)
    {
        cin >> element;
        ListNode *new_node = new ListNode(element, list->next);
        list->next = new_node;
        list = list->next;
    }
    return head;
}

void print_list(ListNode *list)
{
    while (list)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *pre_node = list1;
        ListNode *cur = pre_node->next;
        int start = a - 1, end = b - a;
        while (start--)
        {
            pre_node = pre_node->next;
            cur = pre_node->next;
        }

        pre_node->next = list2;

        while (end--)
        {
            cur = cur->next;
        }

        while (list2->next)
        {
            list2 = list2->next;
        }

        list2->next = cur->next;

        return list1;
    }
};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    ListNode *list1 = insert_node_tail(m);
    ListNode *list2 = insert_node_tail(n);
    ListNode *list;
    Solution slt;
    int a, b;
    cin >> a >> b;
    list = slt.mergeInBetween(list1, a, b, list2);
    // print_list(list1);
    // print_list(list2);
    print_list(list);
}
