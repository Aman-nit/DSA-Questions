#include <iostream>
#include <math.h>
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
    cout << "Enter the data:-";
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
bool kThAncestor(node *root, int k, int p)
{

    // Base
    if (root == NULL)
    {
        cout << "Oops! ,Tree is Empty";
        return false;
    }
    if (root->data == p)
    {
        cout << "There is only data that is root node ";
        return true;
    }
    bool leftAns = kThAncestor(root->left, k, p);
    bool rightAns = kThAncestor(root->right, k, p);

    if (leftAns == true || rightAns == true)
    {
        k--;
        if (k == 0)
        {
            cout << root->data;
            return false;
        }
    }
}
int main()
{
    cout << "Root data of the tree." << endl;
    node *root = buildTree();
    int p, k;
    cout << "Enter the data you want to know the kth Ancestor :-";
    cin >> p;
    cout << "Enter the value of k:-";
    cin >> k;
    kThAncestor(root, k, p);
    return 0;
}