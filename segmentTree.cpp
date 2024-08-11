
// Segment tree making
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long data;
    int leftindex;
    int rightindex;
    Node *left;
    Node *right;
    Node(int leftindex, int rightindex)
    {
        this->leftindex = leftindex;
        this->rightindex = rightindex;
        this->left = NULL;
        this->right = NULL;
    }
};

// createing a tree using
Node *root;
Node *ConstructTree(vector<long long> &num, int left, int right) // left right are indexs
{
    if (left == right)
    {
        Node *leaf = new Node(left, right);
        leaf->data = num[left];
        return leaf;
    }
    Node *node = new Node(left, right);
    int mid = left + (right - left) / 2;
    node->left = ConstructTree(num, left, mid);
    node->right = ConstructTree(num, mid + 1, right);
    node->data = node->left->data + node->right->data;
    return node;
}

long long operation(Node *node, int start, int end)
{
    if (node->leftindex >= start && node->rightindex <= end)
    {
        return node->data;
    }
    else if ((node->leftindex > end) || (node->rightindex < start))
    {
        return 0; // or dfault value you want to return // for min return INT_MAX // for sum return 0
    }
    else
    {
        return operation(node->left, start, end) + operation(node->right, start, end);
    }
}
long long query(int left, int right)
{ //    Node *node=root;
    return operation(root, left, right);
}
long long updateOperation(Node *node, int index, int value)
{
    if (index >= node->leftindex && index <= node->rightindex)
    {
        if (index == node->leftindex && index == node->rightindex)
        {
            node->data = value;
            return node->data;
        }
        else
        {
            long long left = updateOperation(node->left, index, value);
            long long right = updateOperation(node->right, index, value);

            node->data = left + right;
            return node->data;
        }
    }

    return node->data;
}
void update(int index, int value)
{
    Node *node = root;
    root->data = updateOperation(node, index, value);
    return;
}
void print(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    print(node->left);
    print(node->right);
}
void solve(vector<long long> num)
{
    int n = num.size();
    root = ConstructTree(num, 1, n - 1);
}

int n, m;
int main()
{
    cin >> n >> m;
    vector<long long> num;
    num.push_back(0);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        num.push_back(x);
    }

    solve(num);

    for (int i = 0; i < m; ++i)
    {
        int k, left, right;
        cin >> k >> left >> right;
        if (k == 1)
        {
            update(left, right);
        }
        else
        {
            cout << query(left, right) << endl;
        }
    }
    // print(root);

    return 0;
}
