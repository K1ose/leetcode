/* 155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。


示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.


提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack
{
public:
    /* 这道题的问题在于，需要在pop()和top()的时候仍能够得到数据， 又需要得到stack里最小的元素，因此需要两个stack互相配合，一个stack记录常规的元素，另一个stack为min_stack，用于存放stack中的最小元素 */

    stack<int> stk;     /* 存放常规元素 */
    stack<int> min_stk; /* 存放最小元素 */

    MinStack()
    {
        min_stk.push(INT32_MAX); /* min_stack初始化的时候，存放最大的元素 */
    }

    void push(int val)
    {
        /* 每次push的时候，min_stack 和 stack 都push入元素，但是min_stack只push最小元素 */
        stk.push(val);
        min_stk.push(min(val, min_stk.top()));
    }

    void pop()
    {
        stk.pop();
        min_stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    MinStack MS;
    MS.push(0);
    MS.push(1);
    MS.push(0);
    cout << MS.getMin() << endl;
    MS.pop();
    // MS.pop();
    // MS.push(-6);
    cout << MS.getMin() << endl;
    return 0;
}
