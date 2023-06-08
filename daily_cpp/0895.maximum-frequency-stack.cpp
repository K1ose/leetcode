/* 895. 最大频率栈
设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出出现频率最高的元素。

实现 FreqStack 类:

FreqStack() 构造一个空的堆栈。
void push(int val) 将一个整数 val 压入栈顶。
int pop() 删除并返回堆栈中出现频率最高的元素。
如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。


示例 1：

输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
FreqStack = new FreqStack();
freqStack.push (5);//堆栈为 [5]
freqStack.push (7);//堆栈是 [5,7]
freqStack.push (5);//堆栈是 [5,7,5]
freqStack.push (7);//堆栈是 [5,7,5,7]
freqStack.push (4);//堆栈是 [5,7,5,7,4]
freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。


提示：

0 <= val <= 109
push 和 pop 的操作数不大于 2 * 104。
输入保证在调用 pop 之前堆栈中至少有一个元素。
 */
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class FreqStack
{
    /* 哈希表+元素索引 + 元素频率+栈 */
private:
    unordered_map<int, int> freq;              /* 存储val（val为索引）以及其存入的次数 */
    unordered_map<int, stack<int>> freq_stack; /* 存入次数相同的val（val为索引）放在同一个栈 */
    int max_freq;                              /* 更新最高频率的val */

public:
    FreqStack()
    {
        max_freq = 0;
    }

    void push(int val)
    {
        freq[val]++;                         /* val压入次数+1 */
        freq_stack[freq[val]].push(val);     /* 找到val总的压入次数，以次数为索引压入val */
        max_freq = max(max_freq, freq[val]); /* 更新压入次数最大值 */
    }

    int pop()
    {
        int val = freq_stack[max_freq].top(); /* val为频率最大值的栈顶元素 */
        freq[val]--;                          /* val对应频率-1 */
        freq_stack[max_freq].pop();           /* 弹出 */
        if (freq_stack[max_freq].empty())     /* 如果最高频率的栈为空，则max_freq-- */
            max_freq--;
        return val;
    }
};

int main(int argc, char const *argv[])
{
    FreqStack *fs = new FreqStack();
    for (int i = 0; i < 40; i++)
        fs->push(i);
    for (int i = 0; i < 20; i++)
        fs->push(i);
    for (int i = 0; i < 10; i++)
        fs->push(i);
    fs->push(7);

    return 0;
}
