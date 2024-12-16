// WE HAVE TO RETURN OR PRINT THE SUM OF THE LONGEST PATH FROM THE ROOT NODE TO LEAF NODE
#include <iostream>
using namespace std;
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
void sumOfLongestBloodLine(node *root, int &maxLen, int &maxSum, int len, int sum)
{

    if ((root == NULL))
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }
    sum = sum + root->data;
    sumOfLongestBloodLine(root->left, maxLen, maxSum, len + 1, sum);
    sumOfLongestBloodLine(root->right, maxLen, maxSum, len + 1, sum);
}
int main()
{
    node *root = buildTree();
    int maxSum = 0;
    int maxLen = 0;
    int len = 0;
    int sum = 0;
    sumOfLongestBloodLine(root, maxLen, maxSum, len, sum);
    cout << "Max number of node is " << maxLen << " and the sum of the node is " << maxSum << endl;

    return 0;
}