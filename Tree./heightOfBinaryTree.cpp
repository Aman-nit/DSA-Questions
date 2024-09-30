// LONGEST PATH BETWEEN ROOT NODE AND THE LEAF NODE. THE NUMBER OF NODES PRESENT IN THE LONGEST PATH IS CALLED HEIGHT OF THE BINARY TREE.

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
int heightOfBinaryTree(node *root)
{

    // Base case: if the node is NULL, height is 0
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

int main()
{

    node *root = buildTree();

    if (root == NULL)
    {
        cout << "Oops!. Binary tree is empty..";
        return 0;
    }
    else
    {
        int height = heightOfBinaryTree(root);
        cout << "Height of the Binary Tree is " << height;
    }
}