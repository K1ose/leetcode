/* 1419. 数青蛙
给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。

请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。



示例 1：

输入：croakOfFrogs = "croakcroak"
输出：1
解释：一只青蛙 “呱呱” 两次
示例 2：

输入：croakOfFrogs = "crcoakroak"
输出：2
解释：最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "crcoakroak"
第二只青蛙 "crcoakroak"
示例 3：

输入：croakOfFrogs = "croakcrook"
输出：-1
解释：给出的字符串不是 "croak" 的有效组合。


提示：

1 <= croakOfFrogs.length <= 105
字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k' */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        if (croakOfFrogs.size() % 5 != 0)
        {
            return -1;
        }
        int res = 0;
        unordered_map<char, int> umap = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for (char c : croakOfFrogs)
        {
            /* TODO */
        }
    }
};

void printHeart()
{
    const double PI = 3.14159265358979323846;
    const int WIDTH = 70;
    const int HEIGHT = 40;
    const double MIN_X = -3.5;
    const double MAX_X = 3.5;
    const double MIN_Y = -2.5;
    const double MAX_Y = 2.5;

    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            double x = j * (MAX_X - MIN_X) / WIDTH + MIN_X;
            double y = i * (MAX_Y - MIN_Y) / HEIGHT + MIN_Y;
            double f = pow(x * x + y * y - 1, 3) - x * x * y * y * y;
            if (f <= 0.0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    printHeart();
    return 0;
}