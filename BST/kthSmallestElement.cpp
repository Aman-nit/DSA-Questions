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
int kthSmallestElement(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    // INORDER TRAVERSAL
    // left
    int leftAns = kthSmallestElement(root->left, k);
    if (leftAns != -1)
    {
        return leftAns;
    }

    // node
    k--;
    if (k == 0)
    {
        return root->data;
    }
    int rightAns = kthSmallestElement(root->right, k);
}
int main()
{
    int k;
    node *root = NULL;
    takeInput(root);
    cout << "Enter the value of k :-";
    cin >> k;
    int result = kthSmallestElement(root, k);
    if (result == -1)
    {
        cout << "There are fewer than k elements in the tree." << endl;
    }
    else
    {
        cout << "The " << k << "th smallest element is: " << result << endl;
    }
    return 0;
}