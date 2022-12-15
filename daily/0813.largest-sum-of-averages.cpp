/* 813. 最大平均值和的分组
给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个相邻的非空子数组 。 分数 由每个子数组内的平均值的总和构成。

注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。

返回我们所能得到的最大 分数 是多少。答案误差在 10-6 内被视为是正确的。



示例 1:

输入: nums = [9,1,2,3,9], k = 3
输出: 20.00000
解释:
nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
我们也可以把 nums 分成[9, 1], [2], [3, 9].
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.

示例 2:
输入: nums = [1,2,3,4,5,6,7], k = 4
输出: 20.50000


提示:

1 <= nums.length <= 100
1 <= nums[i] <= 104
1 <= k <= nums.length

 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution
{
public:
    template <typename T>
    void print_arr(vector<T> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    void print_matrix(vector<vector<T>> matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    /* 快速排序 */
    // int partition(vector<int> &nums, int low, int high)
    // {
    //     int pivot = nums[low];
    //     while (low < high)
    //     {
    //         /* 从右至左，找到小于pivot的元素 */
    //         while (low < high && nums[high] >= pivot)
    //             --high;
    //         nums[low] = nums[high];

    //         /* 从左至右，找到大于pivot的元素 */
    //         while (low < high && nums[low] <= pivot)
    //             ++low;
    //         nums[high] = nums[low];
    //     }
    //     nums[low] = pivot;
    //     return low;
    // }

    // void quick_sort(vector<int> &nums, int low, int high)
    // {
    //     if (low < high)
    //     {
    //         int pivotpos = partition(nums, low, high);
    //         quick_sort(nums, low, pivotpos - 1);
    //         quick_sort(nums, pivotpos + 1, high);
    //     }
    // }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        /* 动态规划 */
        /*  {dp}[i][j] 表示 nums 在区间 [0, i-1] 被切分成 j 个子数组的最大平均值和，显然 i ≥ j 。有两种情况：
        1. 当j=1时，dp[i][j]是对应区间[0,i-1]的平均值
        2. 当j>1时，区间[0,i-1]可以被分为[0,x-1]和[x, i-1]两个部分，dp[i][j]等于所有这些合法切分后的平均值和的最大值

        状态转移方程为：
        dp[i][j]
        = sum(r=0, i-1)(nums[i])/n    ,j=1
        = max(dp[x][j-1] + sum(r=x, i-1)(nums[r])/(i-x))    ,j>1
         */
        int size = nums.size();
        vector<double> prefix_sum(size + 1);
        for (int i = 0; i < size; i++)
        {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        // print_arr(prefix_sum);

        vector<vector<double>> dp(size + 1, vector<double>(k + 1));
        for (int i = 1; i <= size; i++)
        {
            /* dp[i][1]存储了区间[0,i-1]被分为1组时的前缀平均值 */
            dp[i][1] = prefix_sum[i] / i;
        }

        // print_matrix(dp);
        // 枚举
        // for (int i = 1; i <= size; i++) // 区间[1,size]
        // {
        //     for (int j = 2; j <= k; j++) // 进行分组[2,k]
        //     {
        //         for (int x = 0; x < i; x++) // 枚举区间[0, x]分为j-1组，剩下1组为累加和平均值
        //         {
        //             dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix_sum[i] - prefix_sum[x]) / (i - x));
        //         }
        //     }
        // }

        /* 效率更高 */
        for (int j = 2; j <= k; j++) // 分为j组
        {
            for (int i = j; i <= size; i++) // [j,size]
            {
                for (int x = j - 1; x < i; x++)
                {
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix_sum[i] - prefix_sum[x]) / (i - x));
                    print_matrix(dp);
                }
            }
        }

        return dp[size][k];
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int k;
    cin >> k;

    Solution slt;
    cout << slt.largestSumOfAverages(nums, k) << endl;

    return 0;
}
