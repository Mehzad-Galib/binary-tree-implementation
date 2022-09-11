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

vector<int> result;

void level_order(Node *root)
{
    if (root != NULL)
    {
        level_order(root->leftChild);
        result.push_back(root->val);
        level_order(root->rightChild);
    }
}

int second_minimum(Node *root)
{
    level_order(root);

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size() - 1; i++)
    {
        if (result[i] != result[i + 1])
        {
            return result[i + 1];
        }
    }
    return -1;
}

int main()
{
    Node *a = new Node(2);
    Node *b = new Node(2);
    Node *c = new Node(2);
    Node *d = new Node(2);
    Node *e = new Node(2);

    a->leftChild = b;
    a->rightChild = c;

    c->leftChild = d;
    c->rightChild = e;

    int secMin = second_minimum(a);

    cout << secMin << endl;
}