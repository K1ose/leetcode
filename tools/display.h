#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void print_vec1d_arr(vector<T> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

template <typename T>
void print_vec2d_matrix(vector<vector<T>> matrix)
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

template <typename T1, typename T2>
void print_umap_second_vec(unordered_map<T1, vector<T2>> ums)
{
    for (auto um : ums)
    {
        cout << um.first << ": ";
        print_vec1d_arr(um.second);
    }
}

template <typename T1, typename T2>
void print_umap(unordered_map<T1, T2> ums)
{
    for (auto um : ums)
    {
        cout << um.first << ": " << um.second << endl;
    }
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
