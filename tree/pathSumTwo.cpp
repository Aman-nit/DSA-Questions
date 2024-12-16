// WHILE TRAVELLING ROOT NODE TO LEAF NODE THE TOTAL SUM SHOULD BE EQUAL TO TARGET SUM , AND WE HAVE TO FIND THE PATH WHICH PATH FROM ROOT TO LEAF WILL GIVE THE THE SUM OF NOODES EQUAL TO THE TARGET SUM;

#include <iostream>
#include <vector>
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
void pathSumTwo(node *root, int &targetSUm, vector<vector<int>> &ans)
{
    int currSum = 0;
    vector<int> temp;
    // Base case
    if (root == NULL)
    {
        return;
    }
    // Leafe node
    if (root->left == NULL && root == NULL)
    {
        temp.push_back(root->data);
        currSum += root->data;
        if (currSum == targetSUm)
        {
            ans.push_back(temp);
        }
        return;
    }

    // Include curr node
    temp.push_back(root->data);
    currSum += root->data;

    pathSumTwo(root->left, targetSUm, ans);
    pathSumTwo(root->right, targetSUm, ans);

    //
}

int main()
{
    int targetSum;
    node *root = buildTree();
    cout << "Enter the target sum:-";
    cin >> targetSum;
    vector<vector<int>> ans;

    pathSumTwo(root, targetSum, ans);
    return 0;
}