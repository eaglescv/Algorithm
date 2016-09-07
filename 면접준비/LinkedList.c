#include "LinkedList.h"

//생성
Node* CreateNode(ElementType NewData)
{
	Node* NewNode = ( Node* )malloc( sizeof( Node ) );

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	
	return NewNode;
}

//소멸
void DestroyNode(Node* Node)
{
	free( Node );
}

void DestroyNodeAll(Node** ppHead)
{
	Node* pCurrentNode = (*ppHead);
	Node* pNextNode = NULL;
	while (pCurrentNode)
	{
		pCurrentNode = pCurrentNode->NextNode;
	}
}

//노드 추가
void AppendNode(Node** Head, Node* NewData)
{
	if ((*Head) == NULL)
	{
		*Head = NewData;
	}
	else
	{
		//테일을 찾아 NewNode를 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewData;
	}
}

//노드 삽입
void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if ((*Head) == NULL)
	{
		(*Head) = NewHead;
	}
	else if ((*Head) == Current)
	{
		NewHead->NextNode = Current;
		(*Head) = NewHead;
	}
	else
	{
		Node* SearchNode = (*Head);
		while (SearchNode->NextNode != NULL)
		{
			if (SearchNode->NextNode == Current)
			{
				NewHead->NextNode = SearchNode->NextNode;
				SearchNode->NextNode = NewHead;
				break;
			}
			SearchNode = SearchNode->NextNode;
		}
	}
}

void InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

//노드 탐색
Node* GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

int GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

void Reverse(Node** Head)
{
	Node* Current = *Head;
	if (Current)
	{
		Node* temp = NULL;
		Node* preNode = NULL;
		
		while (Current->NextNode)
		{
			temp = Current->NextNode;
			Current->NextNode = preNode;
			preNode = Current;
			Current = temp;
		}
		Current->NextNode = preNode;
		(*Head) = Current;
	}
}