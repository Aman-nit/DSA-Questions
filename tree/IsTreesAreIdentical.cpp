// WE HAVE TO CHECK THAT IS EVERY NODE'S VALUE AT SAME POSITION OF TO TREES IS SAME THEN THE BOTH TREES ARE IDENTICAL

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
    cout << "Enter the data:-" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    cout << "Enter the data for left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for right node " << data << endl;
    root->right = buildTree();

    return root;
}

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {

        return true;
    }
    else if (root1 != NULL && root2 == NULL)
    {

        return false;
    }
    else if (root1 == NULL && root2 != NULL)
    {

        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool value = root1->data == root2->data;

    if (left && right && value)
    {

        return true;
    }
    else
    {

        return false;
    }
}
int main()
{
    cout << "Enter the data for Tree 1" << endl;
    node *root1 = buildTree();
    cout << "Enter the data for Tree 2" << endl;
    node *root2 = buildTree();

    bool ans = isIdentical(root1, root2);

    if (ans == true)
    {
        cout << "Both tree is identical...";
    }
    else
    {
        cout << "Oops Trees are not identical";
    }
    return 0;
}