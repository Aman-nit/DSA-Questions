// EACH NODE OF TREE WILL BE CONVERTED TO THE SUM OF LEFT SUM OF BINARY TREE RIGHT SUM OF BINARY TREE AND THE VALUE OF CURRNT NODE;
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

    cout << "Enter the data for left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for rightt node " << data << endl;
    root->right = buildTree();

    return root;
}

int convertIntoSumTree(node *root)
{

    // BASE CASE
    if (root == NULL)
    {
        return 0;
    }

    int leftAns = convertIntoSumTree(root->left);
    int rightAns = convertIntoSumTree(root->right);
    root->data = leftAns + root->data + rightAns;

    return root->data;
}
int main()
{
    node *root = buildTree();
    cout << convertIntoSumTree(root);

    return 0;
}
