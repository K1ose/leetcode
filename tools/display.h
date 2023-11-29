#pragma once
#include "struct.h"
#include "program_head.h"
using namespace std;

int datatype;

template <typename T>
void print_vec1d_arr(vector<T> nums)
{
    /* TODO */
    // if (is_same<T, int>::value)
    // {
    //     datatype = 1;
    // }
    // switch (expression)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }
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

template <typename T>
void print_uset(unordered_set<T> us)
{
    cout << "set: ";
    for (auto x : us)
    {
        cout << x << " ";
    }
    cout << endl;
}

void print_linklist(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void print_tree(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root)
    {
        q.push(root);
        while (!q.empty())
        {
            int cur_size = q.size(); /* 记录队列数量，当前层级的结点数量 */
            vector<int> level;

            /* 遍历获取当前层级上的结点，将它们逐一出队，逐一加入孩子结点 */
            for (int i = 0; i < cur_size; i++)
            {
                TreeNode *cur_node = q.front();
                q.pop();
                level.push_back(cur_node->val);

                if (cur_node->left)
                    q.push(cur_node->left);
                if (cur_node->right)
                    q.push(cur_node->right);
            }
            ans.push_back(level);
        }
    }
    print_vec2d_matrix(ans);
}
