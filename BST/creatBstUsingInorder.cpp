#include <iostream>
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

// Function to create a BST from a sorted inorder array
node *creatBstUsingInorder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    int element = inorder[mid];
    node *root = new node(element); // Use the element, not the index
    root->left = creatBstUsingInorder(inorder, s, mid - 1);
    root->right = creatBstUsingInorder(inorder, mid + 1, e); // Fix the right subtree
    return root;
}

// Function to print level order traversal of the BST
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i)
        {
            node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of inorder elements: ";
    cin >> n;
    int inorder[n];
    cout << "Enter the elements of inorder array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    node *root = creatBstUsingInorder(inorder, 0, n - 1); // Fix array bounds
    cout << "Printing BST in Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}
