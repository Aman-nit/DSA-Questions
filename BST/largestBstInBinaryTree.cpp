// **MOST IMPORTANT**
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class nodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBst;
    nodeData()
    {
    }
    nodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBst = valid;
    }
};

// Function to build the binary tree
node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // -1 represents NULL
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter data for the left part of node " << data << endl;
    root->left = buildTree();

    cout << "Enter data for the right part of node " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to perform level order traversal of the tree
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for the end of the current level

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // New level

            if (!q.empty())
            {
                q.push(NULL); // Mark the next level
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//
nodeData largestBstInBinaryTree(node *root, int &ans)
{
    // base casae
    if (root == NULL)
    {
        nodeData temp(0, INT16_MIN, INT16_MAX, true);
        return temp;
    }

    nodeData leftKaAns = largestBstInBinaryTree(root->left, ans);
    nodeData rightKaAns = largestBstInBinaryTree(root->right, ans);

    // checking
    nodeData currNodeKaAns;
    currNodeKaAns.size = leftKaAns.size + rightKaAns.size + 1;
    currNodeKaAns.maxVal = max(root->data, rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root->data, leftKaAns.minVal);

    if (leftKaAns.validBst && rightKaAns.validBst && (root->data > leftKaAns.maxVal && root->data < rightKaAns.minVal))
    {
        currNodeKaAns.validBst = true;
    }
    else
    {
        currNodeKaAns.validBst = false;
    }

    if (currNodeKaAns.validBst)
    {
        ans = max(ans, currNodeKaAns.size);
    }
    return currNodeKaAns;
}

int main()
{
    // Creating a binary tree
    node *root = buildTree();
    cout << "Level order traversal of the tree:" << endl;
    levelOrderTraversal(root);
    int ans = 0;
    largestBstInBinaryTree(root, ans);
    cout << "Largest BST in Binary tree has  " << ans << " Nodes" << endl;

    return 0;
}
