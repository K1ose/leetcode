/* 剑指 Offer 52. 两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共节点。

如下面的两个链表：

在节点 c1 开始相交。



示例 1：

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。



示例 2：

输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。



示例 3：

输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。



注意：

    如果两个链表没有交点，返回 null.
    在返回结果后，两个链表仍须保持原有的结构。
    可假定整个链表结构中没有循环。
    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
    本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

 */
#include <iostream>
#include <vector>
#include "../tools/display.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    /* 双指针 */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /* 假设链表headA和链表headB有公共节点，在公共节点前，headA有a个节点，而headB有b个节点，公共部分共有c个节点。即：headA长度为 a+c ， headB长度为 b+c 。
        那么各自的指针在进行遍历的时候，headA的指针只需要遍历a+c+b，headB的指针遍历b+c+a，二者即可到达公共节点。所以在遍历完各自节点后，交换链表继续遍历即可
         */
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            if (!pA)
            {
                pA = headB;
            }
            else
            {
                pA = pA->next;
            }

            if (!pB)
            {
                pB = headA;
            }
            else
            {
                pB = pB->next;
            }
        }
        return pA;
    }

    /* 另一种解法是unordered_set解法，通过遍历一个链表，存储每个节点的地址，然后再遍历另一个链表，寻找是否有相同地址空间的指针即可 */
};

int main(int argc, char const *argv[])
{

    return 0;
}
