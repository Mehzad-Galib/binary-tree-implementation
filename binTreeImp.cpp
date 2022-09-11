#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}

void printTree(treeNode *root, int level)
{
    if (root == NULL) // when the tree is empty
    {
        return;
    }
    // for case 1, checking should be there

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }

    else // case 2
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

void inOrder(treeNode *root, string &chk)
{ // left root right

    if (root == NULL)
        return;

    inOrder(root->leftChild, chk);
    chk += to_string(root->data);

    inOrder(root->rightChild, chk);
}

void preOrder(treeNode *root, string &chk)
{ // root left right

    if (root == NULL)
        return;

    chk += to_string(root->data);
    preOrder(root->leftChild, chk);

    preOrder(root->rightChild, chk);
}

void postOrder(treeNode *root, string &chk) // left right root
{

    if (root == NULL)
        return;

    postOrder(root->leftChild, chk);

    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

int main()
{
    int n;
    cin >> n;

    treeNode *allNodes[n];

    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;

        // check if user inputs n but types more than n
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid Index" << endl;
            break;
        }

        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    cout << "Tree formation" << endl;
    printTree(allNodes[0], 0);

    // string inordtrav = "";
    // string preordtrav = "";
    // string postordtrav = "";

    // inOrder(allNodes[0], inordtrav);
    // preOrder(allNodes[0], preordtrav);
    // postOrder(allNodes[0], postordtrav);

    // cout << "In-order Traversal: " << inordtrav << endl;

    // cout << "Pre-order Traversal: " << preordtrav << endl;

    // cout << "Post-order Traversal: " << postordtrav << endl;
}

/*
in-order: left root right
post-order: left right root
pre-order: root left right
Input
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

(print template)

Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6

In-order Traversal: 314075826
Pre-order Traversal: 013425786
Post-order Traversal: 341785620

value fix korchi pre dekhe, position fix korchi in dekhe
*/