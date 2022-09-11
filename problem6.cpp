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

Node *invert_tree(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        Node *temp;
        invert_tree(root->left);
        invert_tree(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
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

    Node *a = new Node(3);
    Node *b = new Node(9);
    Node *c = new Node(20);
    Node *d = new Node(15);
    Node *e = new Node(7);

    a->left = b;
    a->right = c;

    c->left = d;
    c->right = e;

    // zigzag_order(a);
    cout << "before inversion:";
    print_tree(a);

    Node *inverted = invert_tree(a);
    cout << endl;
    cout << "after inversion:";
    print_tree(a);
}