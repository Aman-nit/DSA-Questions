// Convert a given DOUBLY LINKED  Binary Search Tree into awithout using a extra space
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

void bstToSortedDll(node *root, node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // Right subtree into ll
    bstToSortedDll(root->right, head);

    // Attach root node
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    // updating head
    head = root;

    // Left subtree into ll
    bstToSortedDll(root->left, head);
}
void printLinkedList(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}
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
node *sortedLinkedListToBst(node *&head, int n)
{
    // base case
    if (n <= 0)
    {
        return NULL;
    }
    node *leftSubtree = sortedLinkedListToBst(head, n - n / 2 - 1);

    node *root = head;
    root->left = leftSubtree;
    head = head->right;

    // right part solve krni hai
    root->right = sortedLinkedListToBst(head, n / 2);
    return root;
}

int main()
{
    int n;
    cout << "Enter the number of nodes  in linked list:-";
    cin >> n;
    int inorder[n];
    cout << "Enter the data of the nodes:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    int s = 0;
    int e = n - 1;
    cout << "Convering array elemnts into BST...." << endl;
    node *root = creatBstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);
    cout << "Printing sorted Linked list...." << endl;
    node *head = NULL;
    bstToSortedDll(root, head);
    printLinkedList(head);
    node *root1 = sortedLinkedListToBst(head, n);
    cout << "Printiing Linked List to Binary Search Tree..." << endl;
    levelOrderTraversal(root1);
}