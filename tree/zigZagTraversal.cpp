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

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<node *> q;
    q.push(root);
    int size = q.size();
    bool leftTOrigh = true;
    vector<int> ans(size);
    while (!q.empty())
    {
        // level process
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftTOrigh ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // change the direction
        leftTOrigh = !leftTOrigh;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{

    return 0;
}