/* 面试题 05.02. 二进制数转字符串

二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。

示例1:

 输入：0.625
 输出："0.101"

示例2:

 输入：0.1
 输出："ERROR"
 提示：0.1无法被二进制准确表示



提示：

    32位包括输出中的 "0." 这两位。
    题目保证输入用例的小数位数最多只有 6 位

 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /* 题目有一个问题，使用double传递参数num。0.2868311060592532本身不能用二进制表示，但是由于double不够精确，答案是0.010010010110110111000011011011，不过值得一提的是，题目保证输入用例的小数位数最多只有 6 位 */
    string printBin(double num)
    {
        /* 将实数的十进制表示转换成二进制表示的方法是：每次将实数乘以 2，将此时的整数部分添加到二进制表示的末尾，然后将整数部分置为 0，重复上述操作，直到小数部分变成 0 或者小数部分出现循环时结束操作。当小数部分变成 0 时，得到二进制表示下的有限小数；当小数部分出现循环时，得到二进制表示下的无限循环小数。 */

        string res = "0.";
        while (res.size() <= 32 && num != 0)
        {
            num *= 2; /* 将一个数乘以 2 的效果是将小数点向右移动一位 */
            int digit = num;
            res.push_back(digit + '0'); /* 使用 +'0' 转为 char 型 */
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }

    /* 至多循环六次 */
    string printBin(double num)
    {
        string bin = "0.";
        for (int i = 0; i < 6; ++i)
        { // 至多循环 6 次
            num *= 2;
            if (num < 1)
                bin += '0';
            else
            {
                bin += '1';
                if (--num == 0)
                    return bin;
            }
        }
        return "ERROR";
    }
};

int main(int argc, char const *argv[])
{
    double num;
    cin >> num;
    Solution slt;
    cout << slt.printBin(num) << endl;
    return 0;
}
