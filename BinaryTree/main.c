#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    Tree *myTree = CreateTtee();
    AddNode(myTree, 11.4);
    AddNode(myTree, 15.7);
    AddNode(myTree, 4.5);
    PrintTree(myTree);
    Node *nodeToDel = FindNode(myTree, 4.5);
    printf("\nNow I am deleting node 4.5\n");
    DeleteNode(myTree, nodeToDel->value);
    PrintTree(myTree);
    printf("\nNow I am deleting node 11.4 and 15.7\n");
    DeleteNode(myTree, 11.4);
    DeleteNode(myTree, 15.7);
    PrintTree(myTree);
    DeleteTree(myTree);
    return 0;
}
