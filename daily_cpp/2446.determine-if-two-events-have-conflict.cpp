/* 2446. 判断两个事件是否存在冲突
给你两个字符串数组 event1 和 event2 ，表示发生在同一天的两个闭区间时间段事件，其中：

event1 = [startTime1, endTime1] 且
event2 = [startTime2, endTime2]
事件的时间为有效的 24 小时制且按 HH:MM 格式给出。

当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现 冲突 。

如果两个事件之间存在冲突，返回 true ；否则，返回 false 。



示例 1：

输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
输出：true
解释：两个事件在 2:00 出现交集。
示例 2：

输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
输出：true
解释：两个事件的交集从 01:20 开始，到 02:00 结束。
示例 3：

输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
输出：false
解释：两个事件不存在交集。


提示：

evnet1.length == event2.length == 2.
event1[i].length == event2[i].length == 5
startTime1 <= endTime1
startTime2 <= endTime2
所有事件的时间都按照 HH:MM 格式给出 */
#include "../tools/program_head.h"
using namespace std;

class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int start_time1 = ((event1[0][0] - '0') * 10 + event1[0][1] - '0') * 60 + (event1[0][3] - '0') * 10 + event1[0][4] - '0';
        int end_time1 = ((event1[1][0] - '0') * 10 + event1[1][1] - '0') * 60 + (event1[1][3] - '0') * 10 + event1[1][4] - '0';

        int start_time2 = ((event2[0][0] - '0') * 10 + event2[0][1] - '0') * 60 + (event2[0][3] - '0') * 10 + event2[0][4] - '0';
        int end_time2 = ((event2[1][0] - '0') * 10 + event2[1][1] - '0') * 60 + (event2[1][3] - '0') * 10 + event2[1][4] - '0';

        bool res = max(start_time1, start_time2) <= min(end_time1, end_time2) ? true : false;
        return res;

        /* return !(event1[1] < event2[0] || event2[1] < event1[0]); */
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
