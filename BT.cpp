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
// void level_order(Node *root)
// {

//     if (root == NULL || root->val == -1)
//     {
//         return;
//     }
//     level_order(root->left);
//     int data = root->val;
//     cout << data << endl;
//     level_order(root->right);
// }
// pre-order/level-order
int array[5];
int count = 0;
void level_order(Node *root)
{

    if (root == NULL || root->val == -1)
    {
        return;
    }

    level_order(root->left);
    level_order(root->right);
    int data = root->val;
    array[count] = data;
    count++;
    cout << data << endl;
}

int main()
{
    // int rootUser;
    // cout << "Enter tree root: ";
    // cin >> rootUser;
    // Node *root = new Node(rootUser);

    // cout << "Enter left child of root: " << rootUser << endl;

    // int leftOfRoot;
    // cin >> leftOfRoot;

    Node *a = new Node(3);
    Node *b = new Node(9);
    Node *c = new Node(20);
    Node *d = new Node(15);
    Node *e = new Node(7);

    a->left = b;
    a->right = c;

    c->left = d;
    c->right = e;

    level_order(a);
    for (int i = 0; i < array.length(); i++)
    {
        cout << array[i];
    }
}