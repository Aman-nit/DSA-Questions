// WE  ARE MOVING VERTICALLY UP TO DOWN AND SHIFTING LEFT TO WRITE AND SIMPLY PRINTING THE NODES , WE ARE GOING TO US MAPS,ITS BECAUSE WE ARE MARKING NUMBERS AS ROOT NODES AS 0 AND LEFT WILL CONSIDER TO -VE AND WRITE AS +VE EACH POSSIBLE VERTICAL LINE ,
// AND PRINTING -VE THEN 0 AND THEN +VE VERTICAL LINE MARKED BY US

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
vector<int> vericalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    node *root = buildTree();
    cout << "Printing tree in verical order...." << endl;
    vector<int> ans = vericalOrder(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}