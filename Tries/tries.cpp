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
void insertWord(triNode *root, string word)
{
    cout << "Inserting " << word << endl;

    // Base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    // Find index of the first char of the word
    char ch = word[0];
    int index = ch - 'A';
    triNode *child;

    // first char of word  is present in root node
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    // first char of word  is not present in root node
    else
    {
        child = new triNode(ch);
        root->children[index] = child;
    }

    // first char of the word inserted successfully

    // Inserting remaining char of the word by using recursion
    insertWord(child, word.substr(1));
}

int main()
{

    triNode *root = new triNode('\0');

    insertWord(root, "coding ");

    return 0;
}