/* 1287. Element Appearing More Than 25% In Sorted Array
Easy
957
51
Companies
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1


Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0, cur = arr[0];
        for (auto x : arr)
        {
            if (x == cur)
            {
                cnt++;
                if (cnt * 4 > n)
                {
                    return cur;
                }
            }

            else
            {
                cnt = 1;
                continue;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    Solution slt;
    cout << slt.findSpecialInteger(arr);
    return 0;
}
