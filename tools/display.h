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
void print_pair(pair<T1, T2> p)
{
    cout << p.first << " " << p.second << endl;
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

template <typename T1, typename T2, typename T3>
void print_umap_second_pair(unordered_map<T1, pair<T1, T2>> ums)
{
    for (auto um : ums)
    {
        cout << um.first << ": ";
        print_pair(um.second);
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

vector<int> levelOrderToVector(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> result;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (node == nullptr)
        {
            result.push_back(INT_MIN);
            continue;
        }

        result.push_back(node->val);

        if (node->left || node->right || !q.empty())
        {
            q.push(node->left);
            q.push(node->right);
        }
    }

    return result;
}

void printGivenLevel(const vector<int> &vec, int level, int depth)
{
    int spaces = pow(2, depth - level) - 1;
    int numElements = pow(2, level - 1);
    int startIdx = pow(2, level - 1) - 1;
    int endIdx = startIdx + numElements;

    for (int i = startIdx; i < endIdx && i < vec.size(); ++i)
    {
        cout << string(spaces, ' ');
        if (vec[i] != INT_MIN)
            cout << vec[i];
        else
            cout << " ";
        cout << string(spaces, ' ');
        if (i < endIdx - 1)
            cout << " ";
    }
    cout << endl;
}

void print_tree(const vector<int> &vec)
{
    int depth = ceil(log2(vec.size() + 1));
    for (int level = 1; level <= depth; ++level)
    {
        printGivenLevel(vec, level, depth);
        if (level < depth)
        {
            // Print branch for non-last levels
            int spacesBetweenBranches = pow(2, depth - level) - 1;
            int branches = pow(2, level - 1);
            for (int j = 0; j < branches && (j * spacesBetweenBranches * 2 + branches - 1) < vec.size(); ++j)
            {
                cout << string((spacesBetweenBranches + 1) / 2, ' ') << "/";
                cout << string(spacesBetweenBranches, ' ') << "\\";
                cout << string((spacesBetweenBranches + 1) / 2, ' ');
                if (j < branches - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
}
