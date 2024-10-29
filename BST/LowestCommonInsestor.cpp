#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *builtbst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    else if (root->data > data)
    {
        root->left = builtbst(root->left, data);
    }
    else
    {
        root->right = builtbst(root->right, data);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cout << "Enter the data of node(-1 to end):-" << endl;
    cin >> data;
    while (data != -1)
    {
        root = builtbst(root, data);
        cout << "Enter the data of node(-1 to end):-" << endl;
        cin >> data;
    }
}
node *lowestCommonAncestor(node *root, int p, int q)
{
    // Base case
    if (root == NULL)
    {
        return NULL;
    }
    // case 1
    if (p < root->data && q < root->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    // case 2
    if (p > root->data && q > root->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    // case 3
    return root;
}
int main()
{
    int p, q;
    node *root = NULL;
    takeInput(root);
    cout << "Enter the two node data to find there lowest common ancestor:-";
    cin >> p >> q;
    node *ans = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of the " << p << " , " << q << " is " << ans->data;
}