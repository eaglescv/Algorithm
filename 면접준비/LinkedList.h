#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

//함수 원형
Node* CreateNode(ElementType NewData);
void DestroyNode(Node* Node);
void AppendNode(Node** Head, Node* NewData);
void InsertAfter(Node* Current, Node* NewNode);
void InsertBefore(Node** Head, Node* Current, Node* NewHead);
void InsertNewHead(Node** Head, Node* NewHead);
void RemoveNode(Node** Head, Node* Remove);
Node* GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);
void Reverse(Node** Head);
#endif	//__LINKED_LIST_H__