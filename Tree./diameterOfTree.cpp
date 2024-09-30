// THE LONGEST PATH BETWEEN ANY TWO END NODES(ROOT NODE,LEAF NODE), THE NUMBER OF NODES PRESENT BETWEEN THE LONGEST PATH IS THE DIA METERE OF THE BINARY TREE

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
    cout << "Enter the data:-";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    cout << "Enter the data of left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data of right node " << data << endl;
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
int diameterofBinaryTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = diameterofBinaryTree(root->left);
    int opt2 = diameterofBinaryTree(root->right);
    int opt3 = heightOfBinaryTree(root->left) + 1 + heightOfBinaryTree(root->right);
    int ans = max(opt1, max(opt2, opt3));
    return ans;
}
int main()
{

    node *root = buildTree();
    cout << "Diameter of given Binary Tree is " << diameterofBinaryTree(root);

    return 0;
}