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

node *buildTree()
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);

    cout << "Enter the data for the left node of " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for the right node of " << data << endl;
    root->right = buildTree();

    return root;
}

node *lowestCommonAncestor(node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }

    // If either p or q matches the root's data, return root
    if (root->data == p || root->data == q)
    {
        return root;
    }

    // Recurse for the left and right subtrees
    node *leftLCA = lowestCommonAncestor(root->left, p, q);
    node *rightLCA = lowestCommonAncestor(root->right, p, q);

    // If p and q are found in left and right subtrees, return root as LCA
    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }

    // Otherwise return the non-NULL child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main()
{
    node *root = buildTree();
    int p, q;
    cout << "Enter the value of p: ";
    cin >> p;
    cout << "Enter the value of q: ";
    cin >> q;

    node *LCA = lowestCommonAncestor(root, p, q);

    if (LCA != NULL)
    {
        cout << "Lowest Common Ancestor is: " << LCA->data << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    return 0;
}
