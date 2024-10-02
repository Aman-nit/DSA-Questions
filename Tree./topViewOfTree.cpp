// WE HAVE TO GIVE OR PRINT THE DATA SUCH WAY WE ARE SEEING THE TREE FROM THE TOP OF TREE , IN THIS SENARIO ONLY WE ARE USING LEVEL ORDER TRAVERSAL AND EACH INDEX FROM ROOT NODE LEFT TO RIGHT WE WILL ONLY PRINT FIRST ELEMENT BECAUSE OTHER ELEMENT IN EACH VERTICAL LINE WILL BE HIDEEN BY FIRST NODE OF THAT VERTICAL LINE
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
vector<int> topView(node *root)
{

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;

        // If one value is present for a hd , then eat Five Star
        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    cout << "Printing tree from Top View....." << endl;
    vector<int> ans = topView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}