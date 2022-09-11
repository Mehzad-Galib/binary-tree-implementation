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

void average_level_sum(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int level_sum = 0;
        int level_count = 0;
        queue<Node *> temp;
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            level_sum += current->val;
            level_count++;
            if (current->left != NULL)
            {
                temp.push(current->left);
            }
            if (current->right != NULL)
            {
                temp.push(current->right);
            }
        }
        q = temp;
        double result = (level_sum * 1.0) / level_count;
        cout << result << " ";
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

    average_level_sum(a);
}