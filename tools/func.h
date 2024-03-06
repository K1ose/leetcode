#pragma once
#include "display.h"
#include "program_head.h"

vector<int> deToBi(int num)
{
    vector<int> digits;

    for (; num; num >>= 1)
    {
        digits.push_back(num & 1);
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
