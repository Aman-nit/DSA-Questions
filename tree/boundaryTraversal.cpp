// WE HAVE TO TRAVERSE TREE ONLY THE BOUNDARY NODES
// THIS IS JUST A LEVEL ORDER TRAVERSAL BUT IN THIS CASE WE ARE MOVING 1ST LEVEL LEFT TO WRITE AND THEN SECOND LEVEL RIGHT TO LEFT AND SOO ON..............
#include <iostream>
#include <vector>
#include <queue>

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
void traversalLeft(node *root, vector<int> &ans)
{
    if ((root == NULL) || ((root->left == NULL) && (root->right = NULL)))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        traversalLeft(root->left, ans);
    }
    else
    {
        traversalLeft(root->right, ans);
    }
}
void traversLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    traversLeaf(root->left, ans);
    traversLeaf(root->right, ans);
}
void traverseRight(node *root, vector<int> &ans)
{
    if ((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
    {
        return;
    }
    if (root->right != NULL)
    {
        traverseRight(root->right, ans);
    }
    else
    {

        traverseRight(root->left, ans);
    }

    // wapasaate wakt puss
    ans.push_back(root->data);
}

void boundryTraversal(node *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);

    // left part print/store
    traversalLeft(root->left, ans);
    // Travers leaf nodes
    traversLeaf(root->right, ans);
    // traversing right
    traverseRight(root->right, ans);

    return;
}

int main()
{
    vector<int> ans;
    node *root = buildTree();
    boundryTraversal(root, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
