// Inorder predecessor  of any node its mean the value just befor that node value when the bst is in represented in inorder form
// EX:-2 4 5 6 8 10 11 15 17 20 25 (any bst inorder form is alwasy sorted)
// so in this senario this is a inorder representation of the BST , we are asked to find the inorder prdecessor of 20 soanswer will be 17 , and we can say that the maximum value of  the left subtree of that node will be the inorder predecessor , it is not valid in all the case like when we have to tell to find the predecessor of the node which don't have any left subtree.