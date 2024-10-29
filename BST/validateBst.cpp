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
node *builtBst(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = builtBst(root->left, data);
    }
    else
    {
        root->right = builtBst(root->right, data);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cout << "Enter the data for the node:-" << endl;
    cin >> data;
    while (data != -1)
    {
        root = builtBst(root, data);
        cout << "Enter the data for the node:-" << endl;
        cin >> data;
    }
}
bool validatebst(node *root, int lb, int up)
{

    if (root == NULL)
    {
        return true;
    }
    if (root->data > lb && root->data < up)
    {
        bool leftAns = validatebst(root->left, lb, root->data);
        bool rightAns = validatebst(root->right, root->data, up);
        return leftAns && rightAns;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = NULL;
    takeInput(root);
    int lowerBond = INT32_MIN;
    int uperBond = INT32_MAX;
    bool ans = validatebst(root, uperBond, lowerBond);
    if (ans)
    {
        cout << "Validate..." << endl;
    }
    else
    {
        cout << "Not a Bst.." << endl;
    }
}