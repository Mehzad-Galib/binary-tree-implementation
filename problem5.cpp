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
void zigzag_order(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> currLev;
    stack<Node *> nextLev;

    currLev.push(root);

    bool leftToRight = true;

    while (!currLev.empty())
    {
        Node *temp = currLev.top();
        currLev.pop();

        if (temp != NULL)
        {
            cout << temp->val << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLev.push(temp->left);
                }
                if (temp->right)
                {
                    nextLev.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLev.push(temp->right);
                }

                if (temp->left)
                {
                    nextLev.push(temp->left);
                }
            }
        }

        if (currLev.empty())
        {
            leftToRight = !leftToRight;
            swap(currLev, nextLev);
        }
    }
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

    zigzag_order(a);
}