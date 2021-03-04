#define _CRT_SECURE_NO_WARNINGS_
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include "MyLinkedList.h"

void InitList(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->link = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;

}

void FInsert(List* plist, LData pdata) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = pdata;

	newNode->link = plist->head->link;
	plist->head->link = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData pdata) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = pdata;

	while (pred->link != NULL && plist->comp(pdata, pred->link->data) != 0) {
		pred = pred->link;
	}

	newNode->link = pred->link;
	pred->link = newNode;

	(plist->numOfData)++;
}

void InsertList(List* plist, LData pdata) {
	if (plist->comp == NULL) {
		FInsert(plist, pdata);
	}
	else {
		SInsert(plist, pdata);
	}
}

int FirstNode(List* plist, LData* data) {
	if (plist->head->link == NULL) {
		return FALSE;
	}
	plist->before = plist->head;
	plist->cur = plist->head->link;

	*data = plist->cur->data;
	return TRUE;
}

int NextNode(List* plist, LData* pdata) {
	if (plist->cur->link == NULL) {
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->link;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->link = plist->cur->link;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}