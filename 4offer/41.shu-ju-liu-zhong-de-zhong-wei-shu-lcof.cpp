/* 剑指 Offer 41. 数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

    void addNum(int num) - 从数据流中添加一个整数到数据结构中。
    double findMedian() - 返回目前所有元素的中位数。

示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]

示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]



限制：

    最多会对 addNum、findMedian 进行 50000 次调用。

注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/
 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

/* 用两个优先队列 queMax 和 queMin 分别记录大于中位数的数和小于等于中位数的数。当累计添加的数的数量为奇数时，queMin 中的数的数量比 queMax 多一个，此时中位数为 queMin 的队头。当累计添加的数的数量为偶数时，两个优先队列中的数的数量相同，此时中位数为它们的队头的平均值。

当我们尝试添加一个数 num 到数据结构中，我们需要分情况讨论：

    - num≤max⁡{queMin}
        此时 num 小于等于中位数，我们需要将该数添加到 queMin 中。新的中位数将小于等于原来的中位数，因此我们可能需要将 queMin 中最大的数移动到 queMax 中。

    - num>max⁡{queMin}
        此时 num 大于中位数，我们需要将该数添加到 queMin 中。新的中位数将大于等于原来的中位数，因此我们可能需要将 queMax 中最小的数移动到 queMin 中。

特别地，当累计添加的数的数量为 0 时，我们将 num 添加到 queMin 中。
 */
class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num)
    {
        if (queMin.empty() || num <= queMin.top())
        {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size())
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {
            queMax.push(num);
            if (queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian()
    {
        if (queMin.size() > queMax.size())
        {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char const *argv[])
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(6);
    obj->addNum(10);
    cout << obj->findMedian() << endl;
    obj->addNum(2);
    cout << obj->findMedian() << endl;

    return 0;
}
