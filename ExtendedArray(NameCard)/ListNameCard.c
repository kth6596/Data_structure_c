#include<stdio.h>
#include "ListNameCard.h"

void InitList(List* plist) {
	plist->numOfData = 0; //����Ʈ�� ��� ����
	plist->curPos = -1; //����Ʈ�� �ε���
}

void InsertList(List* plist, Data data) {
	if (plist->numOfData >= ARR_LEN) {
		puts("���� �뷮 �ʰ�");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

//LFisrt�� LNext �Լ� ��ģ �ڵ�

int SearchNode(List* plist, Data* data) {
	if (plist->numOfData == 0 || plist->curPos >= (plist->numOfData) - 1) {
		plist->curPos = -1;
		return FALSE;
	}

	(plist->curPos)++;
	*data = plist->arr[plist->curPos];
	return TRUE;
}

Data RemoveNode(List* plist) {
	int num = plist->numOfData;
	int rpos = plist->curPos;
	Data rdata = plist->arr[rpos];

	for (int i = rpos; i < num - 1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->curPos)--;
	(plist->numOfData)--;

	return rdata;
}

int CountList(List* plist) {
	return plist->numOfData;
}