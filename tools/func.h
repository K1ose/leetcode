#pragma once
#include "display.h"
#include "program_head.h"

template <typename T>
vector<int> deToBi(T num)
{
    vector<int> digits;
    stack<int> stk;
    while (num != 0)
    {
        stk.push(num % 2);
        num = num / 2;
    }
    while (!stk.empty())
    {
        digits.push_back(stk.top());
        stk.pop();
    }
    return digits;
}

template <typename T>
string vectorToString(T *vec)
{
    string str;
    for (auto v : vec)
    {
        str.push_back(v + '0');
    }
    return str;
}
