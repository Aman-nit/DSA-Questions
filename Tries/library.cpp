#include <iostream>
using namespace std;

class triNode
{
public:
    char data;
    triNode *children;
    bool isTerminal;

    triNode(char c)
    {
        data = c;
        children = NULL;
        isTerminal = false;
    }
};
