#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

bool isSame(Node *root1, Node *root2)
{
    // both empty
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
           isSame(root1->leftChild, root2->leftChild) &&
           isSame(root1->rightChild, root2->rightChild);
}

int main()
{
    // root 1 input

    int value, left, right;
    cin >> value >> left >> right;
    Node *tree1 = new Node(value);
    tree1->leftChild = new Node(left);
    tree1->rightChild = new Node(right);

    // root 2 input
    int value2, left2, right2;
    cin >> value2 >> left2 >> right2;
    Node *tree2 = new Node(value2);
    tree2->leftChild = new Node(left2);
    tree2->rightChild = new Node(right2);

    if (isSame(tree1, tree2))
    {
        cout << "Identical";
    }
    else
        cout << "Not Identical";
}