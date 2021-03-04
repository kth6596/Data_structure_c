#include<stdio.h>
#include "MyArrayList.h"

int main(void) {
	int data;
	List newList;

	InitList(&newList);

	for (int a = 1; a < 6; a++) {
		InsertList(&newList, 2 * a - 1);
	}
	
	printf("���� ����� ����: %d\n", CountList(&newList));

	while (SearchNode(&newList, &data)) {
		printf("%d ", data);
	}
	
	printf("\n\n");
	
	while (SearchNode(&newList, &data)) {
		if (data == 9) {
			RemoveNode(&newList);
		}
	}
	
	printf("���� ����� ����: %d\n", CountList(&newList));

	while (SearchNode(&newList, &data)) {
			printf("%d ", data);
		}

	return 0;
}