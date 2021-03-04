#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* link;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* tail;
	Node* before;
	Node* cur;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void InitList(List* plist);
void InsertList(List* plist, LData pdata);

int FirstNode(List* plist, LData* pdata);
int NextNode(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));


#endif __MY_LINKED_LIST_H__