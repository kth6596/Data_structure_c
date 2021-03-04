#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__
#include "NameCard.h"

#define TRUE 1
#define FALSE 0

#define ARR_LEN 100

typedef NameCard* Data;

typedef struct _ArrayList {
	Data arr[ARR_LEN];
	int numOfData;
	int curPos;
} ArrayList;

typedef ArrayList List;

void InitList(List* plist);
void InsertList(List* plist, Data data);

int SearchNode(List* plist, Data* data);

Data RemoveNode(List* plist);
int CountList(List* plist);

#endif