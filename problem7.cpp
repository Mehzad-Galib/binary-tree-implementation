#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int tiltVal(Node *root, int *tilt)
{
    if (root == NULL)
        return 0;

    int left = tiltVal(root->left, tilt);
    int right = tiltVal(root->right, tilt);

    *tilt += abs(left - right);

    return left + right + root->val;
}

int findTilt(Node *root)
{
    int tilt = 0;

    if (root == NULL)
        return 0;

    tiltVal(root, &tilt);
    return tilt;
}

void print_tree(Node *root)
{
    if (root == NULL)
        return;
    print_tree(root->left);
    cout << root->val << " ";
    print_tree(root->right);
}

int main()
{

    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);

    a->left = b;
    a->right = c;

    cout << findTilt(a);
}