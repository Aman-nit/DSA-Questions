// Tries are tree with multiple child

#include <iostream>
using namespace std;

class triNode
{
public:
    char data;
    triNode *children[26];
    bool isTerminal;

    triNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
// void insertWord(triNode *root, string word)
// {
//     cout << "Inserting " << word << endl;

//     // Base case
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }
//     // Find index of the first char of the word
//     char ch = word[0];
//     int index = ch - 'A';
//     triNode *child;

//     // first char of word  is present in root node
//     if (root->children[index] != NULL)
//     {
//         child = root->children[index];
//     }
//     // first char of word  is not present in root node
//     else
//     {
//         child = new triNode(ch);
//         root->children[index] = child;
//     }

//     // first char of the word inserted successfully

//     // Inserting remaining char of the word by using recursion
//     insertWord(child, word.substr(1));
// }

void insertWord(triNode *root, string word)
{
    triNode *current = root;
    for (char ch : word)
    {
        int index = tolower(ch) - 'a'; // Handle lowercase

        if (current->children[index] == NULL)
        {
            current->children[index] = new triNode(ch);
        }

        current = current->children[index];
    }
    current->isTerminal = true;
}
bool searchWord(triNode *root, string word)
{
    // base casae
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    triNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    // recursion will handel other char of the words
    return searchWord(child, word.substr(1));
}
int main()
{

    triNode *root = new triNode('\0');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehlp");
    insertWord(root, "baby");
    insertWord(root, "jaan");
    insertWord(root, "babu");

    if (searchWord(root, "coder"))
    {
        cout << "Present..." << endl;
    }
    else
    {
        cout << " NOt Present..." << endl;
    }

    return 0;
}