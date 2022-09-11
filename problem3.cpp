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

void level_order_reverse(Node *root)
{
    if (root == NULL || root->val == -1)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    stack<int> st;
    Node *current = NULL;
    while (q.size())
    {
        current = q.front();
        q.pop();
        st.push(current->val);
        if (current->right)
        {
            q.push(current->right);
        }
        if (current->left)
        {
            q.push(current->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
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

    level_order_reverse(a);
}