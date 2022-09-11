#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *leftChild;
    Node *rightChild;

    Node(int val)
    {
        this->val = val;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

bool is_unival(Node *root)
{
    if (root == NULL)
        return true;

    if (root->leftChild != NULL && root->val != root->leftChild->val)
    {
        return false;
    }

    if (root->rightChild != NULL && root->val != root->rightChild->val)
    {
        return false;
    }

    return is_unival(root->leftChild) && is_unival(root->rightChild);
}

int main()
{

    Node *a = new Node(1);
    Node *b = new Node(1);
    Node *c = new Node(1);
    Node *d = new Node(1);
    Node *e = new Node(1);
    Node *f = new Node(2);

    a->leftChild = b;
    a->rightChild = c;

    b->leftChild = d;
    b->rightChild = e;

    c->leftChild = f;

    if (is_unival(a))
        cout << "Unival";
    else
        cout << "not unival";
}