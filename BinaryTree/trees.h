#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct __Node
{
    float value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct __Tree
{
    Node *root;
    int count;
} Tree;

Tree *CreateTtee();

void DeleteTree(Tree *myTree);

void PrintTree(Tree *myTree);

void AddNode(Tree *myTree, float value);

void DeleteNode(Tree *myTree, float value);

Node *FindNode(Tree *myTree, float value);


#endif // TREES_H_INCLUDED
