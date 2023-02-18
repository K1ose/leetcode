/* 剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )



示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead","deleteHead"]
[[],[3],[],[],[]]
输出：[null,null,3,-1,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class CQueue
{
public:
    stack<int> stk1; /* 用于入队的栈 */
    stack<int> stk2; /* 用于出队的栈 */

    CQueue()
    {
    }

    void transfer()
    {
        /* 如果入队栈不为空，说明要将里面的元素放置到出队栈中，并将入队栈对应元素弹出 */
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    void appendTail(int value)
    {
        /* 入队栈压入元素 */
        stk1.push(value);
    }

    int deleteHead()
    {
        /* 如果出队栈为空 */
        if (stk2.empty())
        {
            /* 如果入队栈也为空，则代表整个队列中没有元素，直接返回-1 */
            if (stk1.empty())
                return -1;
            /* 如果入队栈不为空，则将入队栈的元素放置到出队栈中 */
            transfer();
        }
        /* 获取出队元素 */
        int val = stk2.top();
        stk2.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */