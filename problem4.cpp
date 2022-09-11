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

// in-order
bool isSymmetric(Node *root)
{
    Node *leftChild = root->left;
    Node *rightChild = root->right;

    if (leftChild->val == rightChild->val)
    {
        if ((leftChild->left->val == rightChild->right->val) && (leftChild->right->val == rightChild->left->val))
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        return false;
    }
}

int main()
{

    Node *a = new Node(1);

    Node *b = new Node(2);
    Node *c = new Node(2);

    Node *d = new Node(3);
    Node *e = new Node(4);
    Node *f = new Node(4);
    Node *g = new Node(3);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    if (isSymmetric(a))
        cout << "symmetric";
    else
        cout << "asymmetric";
}