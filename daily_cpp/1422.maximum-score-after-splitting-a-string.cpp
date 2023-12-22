/* 1422. Maximum Score After Splitting a String
Easy
914
43
Companies
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.



Example 1:

Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3


Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only. */
#include "../tools/program_head.h"
#include "../tools/display.h"
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> zeroCnt, oneCnt;
        int zero_cnt = 0;
        int one_cnt = 0;
        for (auto c : s)
        {
            zero_cnt -= c - '1';
            one_cnt += c - '0';

            zeroCnt.push_back(zero_cnt);
            oneCnt.push_back(one_cnt);
        }

        int max_score = 0;
        for (int i = 0; i < zeroCnt.size(); i++)
        {
            max_score = max(max_score, zeroCnt[i] + oneCnt[zeroCnt.size() - 1] - oneCnt[i]);
        }
        // print_vec1d_arr(zeroCnt);
        // print_vec1d_arr(oneCnt);
        return max_score;
    }
};

int main(int argc, char const *argv[])
{
    string s = "011101";
    Solution slt;
    cout << slt.maxScore(s) << endl;

    return 0;
}
