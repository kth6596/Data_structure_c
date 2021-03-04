#define _CRT_SECURE_NO_WARNINGS_
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include"MyLinkedList.h"

int WhoIsPreced(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void) {
	List list;
	int data;

	InitList(&list);

	SetSortRule(&list, WhoIsPreced);
	
	InsertList(&list, 11);
	InsertList(&list, 22);
	InsertList(&list, 33);
	InsertList(&list, 44);

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (FirstNode(&list, &data)) {
		printf("%d ", data);

		while (NextNode(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	if (FirstNode(&list, &data)) {
		if (data == 44)
			LRemove(&list);

		while (NextNode(&list, &data)) {
			if (data == 44)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));
	
	if (FirstNode(&list, &data)) {
		printf("%d ", data);

		while (NextNode(&list, &data)) {
			printf("%d ", data);
		}
	}
	return 0;
}