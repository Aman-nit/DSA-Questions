// WE ARE PRINTING THOSE NOTED ONLY WHEN WE ARE SEEING THE TREE FROM THE RIGHT OF THE TREE
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    cout << "Enter the data for the left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for the right node " << data << endl;
    root->right = buildTree();
    return root;
}
void rightView(node *root, vector<int> &ans, int level)
{

    if (root == NULL)
    {
        return;
    }
    // entered in new Level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    rightView(root->right, ans, level + 1);
    rightView(root->left, ans, level + 1);
}

int main()
{
    node *root = buildTree();
    cout << "Printing tree from Left View....." << endl;
    vector<int> ans;
    int level = 0;
    rightView(root, ans, level);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}