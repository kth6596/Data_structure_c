#include<stdio.h>
#include "MyArrayList.h"

void InitList(List* plist) {
	plist->numOfData = 0; //리스트의 노드 갯수
	plist->curPos = -1; //리스트의 인덱스
}

void InsertList(List* plist, Data data) {
	if (plist->numOfData >= ARR_LEN) {
		puts("저장 용량 초과");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

//LFisrt와 LNext 함수 합친 코드

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

	for (int i = rpos; i < num-1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->curPos)--;
	(plist->numOfData)--;

	return rdata;
}

int CountList(List* plist) {
	return plist->numOfData;
}
