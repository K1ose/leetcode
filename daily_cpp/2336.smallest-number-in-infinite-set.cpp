/* 2336. 无限集中的最小数字
中等
相关标签
相关企业
提示
现有一个包含所有正整数的集合 [1, 2, 3, 4, 5, ...] 。

实现 SmallestInfiniteSet 类：

SmallestInfiniteSet() 初始化 SmallestInfiniteSet 对象以包含 所有 正整数。
int popSmallest() 移除 并返回该无限集中的最小整数。
void addBack(int num) 如果正整数 num 不 存在于无限集中，则将一个 num 添加 到该无限集中。


示例：

输入
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
输出
[null, null, 1, 2, 3, null, 1, 4, 5]

解释
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 2 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 3 ，并将其从集合中移除。
smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 在上一步中被添加到集合中，
                                   // 且 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 4 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 5 ，并将其从集合中移除。


提示：

1 <= num <= 1000
最多调用 popSmallest 和 addBack 方法 共计 1000 次 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;
class OtherSmallestInfiniteSet
{
public:
    OtherSmallestInfiniteSet()
    {
        _m.insert({INT_MAX, 1});
    }

    int popSmallest()
    {
        // 获取right最小的一个区间的left
        int ret = _m.begin()->second;
        _m.begin()->second++;
        // 区间不存在删除
        if (_m.begin()->first < _m.begin()->second)
        {
            _m.erase(_m.begin());
        }
        return ret;
    }

    void addBack(int num)
    {
        // 查找大于等于num的第一个右区间数
        auto iter = _m.lower_bound(num);
        // 已知right >= num，然后看left是否包含
        if (iter->second <= num)
        {
            // num已经被包含存在
            return;
        }
        else if (iter->second == num + 1)
        {
            // 扩展当前区间，相当于直接连接num这个数到iter区间
            iter->second--;
        }
        else
        {
            // 独立单位大小的区间
            _m.insert({num, num});
        }
    }

private:
    std::map<int, int> _m; // rigtht->left
    // 存取所有的区间{right,left}，按照right依次进行升序排序，各个区间单位[right,left]互不干扰
};

class SmallestInfiniteSet
{
public:
    SmallestInfiniteSet() {}

    int popSmallest()
    {
        if (s.empty())
        {
            int pop_e = min_e;
            min_e++;
            return pop_e;
        }
        int pop_e = *s.begin();
        s.erase(s.begin());
        return pop_e;
    }

    void addBack(int num)
    {
        if (num < min_e)
        {
            s.insert(num);
        }
    }

private:
    int min_e = 1;
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main(int argc, char const *argv[])
{
    SmallestInfiniteSet *sis = new SmallestInfiniteSet();
    cout << sis->popSmallest() << endl;
    sis->addBack(1);
    cout << sis->popSmallest() << endl;
    cout << sis->popSmallest() << endl;
    cout << sis->popSmallest() << endl;
    sis->addBack(2);
    cout << sis->popSmallest() << endl;
    sis->addBack(2);
    cout << sis->popSmallest() << endl;
    cout << sis->popSmallest() << endl;

    return 0;
}
