/* 2661. 找出叠涂元素
给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat 都包含范围 [1，m * n] 内的 所有 整数。

从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。

请你找出 arr 中在 mat 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。



示例 1：

image explanation for example 1
输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
输出：2
解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
示例 2：

image explanation for example 2
输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
输出：3
解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。


提示：

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
arr 中的所有整数 互不相同
mat 中的所有整数 互不相同 */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        /* TODO */
        int m = mat.size();
        // cout << m << endl;
        int n = mat[0].size();
        // cout << n << endl;

        vector<int> rows(m, n); /* there are m rows, n elements in every row */
        vector<int> cols(n, m); /* there are n cols, m elements in every column */
        // print_vec1d_arr(rows);
        // print_vec1d_arr(cols);
        unordered_map<int, pair<int, int>> map_mat;
        unordered_map<int, int> map_arr;
        for (int i = 0; i < m * n; i++)
        {
            map_arr[arr[i]] = i;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int e = mat[i][j];
                map_mat[e] = {i, j};
            }
        }
        int res;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : arr)
        {
            int cur_i = map_mat[x].first;
            int cur_j = map_mat[x].second;
            rows[cur_j]--; /* map[2]={0,1}, map[2].second=1, rows[1]=*/
            cols[cur_i]--; /* map[2]={0,1}, map[2].first=0, rows[1]=*/
            if (rows[cur_j] == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    min1 = min(min1, mat[i][cur_j]);
                }
                return min1 < min2 ? map_arr[min1] : map_arr[min2];
            }
            if (cols[cur_i] == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    min2 = min(min2, mat[cur_i][i]);
                }
                return min1 < min2 ? map_arr[min1] : map_arr[min2];
            }
            print_vec1d_arr(rows);
            print_vec1d_arr(cols);
            cout << endl;
        }
        return 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution slt;
    // vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<int> arr = {1, 3, 4, 2};

    // vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};

    slt.firstCompleteIndex(arr, mat);
    return 0;
}
