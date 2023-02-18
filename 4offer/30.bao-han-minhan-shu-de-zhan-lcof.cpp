/* 剑指 Offer 30. 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。



示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.


提示：

各函数的调用总次数不超过 20000 次
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> stk;    /* 存放元素的栈 */
    stack<int> minstk; /* 存放栈中当前最小元素的栈 */

    /** initialize your data structure here. */
    MinStack()
    {
        minstk.push(INT32_MAX); /* min_stack初始化的时候，存放最大的元素，这样就不用对 minstk 进行判空了 */
    }

    void push(int x)
    {
        /* 每次push元素时，最小栈和普通栈都要压入元素，但是最小栈中压入的是当前最小元素 */
        stk.push(x);

        if (x < minstk.top())
        {
            minstk.push(x);
        }
        else
        {
            minstk.push(minstk.top());
        }
    }

    void pop()
    {
        stk.pop();
        minstk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int min()
    {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
