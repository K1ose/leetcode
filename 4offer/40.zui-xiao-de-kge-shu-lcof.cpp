/* 剑指 Offer 40. 最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。



示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]



限制：

    0 <= k <= arr.length <= 10000
    0 <= arr[i] <= 10000

 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    /* c++中的优先队列是大根堆，即堆顶top()是堆中拥有最大值的节点 */
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
        {
            return {};
        }

        vector<int> res;
        priority_queue<int> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

    /* 排序后输出前k个值 */
    vector<int> getLeastNumbers_sort(vector<int> &arr, int k)
    {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
