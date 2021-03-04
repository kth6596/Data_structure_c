#define _CRT_SECURE_NO_WARNINGS_
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "NameCard.h"
#include "ListNameCard.h"

int main(void) {
	List list;
	NameCard* newCard;
	char compName[NAME_LEN];

	InitList(&list);

	InsertList(&list, newCard = MakeNameCard("�縶õ", "010-1234-1234"));
	InsertList(&list, newCard = MakeNameCard("�ѽ�", "010-1111-2222"));
	InsertList(&list, newCard = MakeNameCard("����", "010-3131-1313"));

	printf("���� ����� ����: %d\n", CountList(&list));

	while (SearchNode(&list, &newCard)) {
		ShowNameCardInfo(newCard);
	}

	printf("\n\n");

	strcpy(compName, "�ѽ�");

	while (SearchNode(&list, &newCard)) {
		if (NameCompare(newCard, compName) == 0) {
			ChangePhoneNum(newCard, "010-1111-1111");
		}
	}

	strcpy(compName, "����");

	while (SearchNode(&list, &newCard)) {
		if (NameCompare(newCard, compName) == 0) {
			newCard = RemoveNode(&list);
			free(newCard);
		}
	}

	printf("���� ����� ����: %d\n", CountList(&list));

	while (SearchNode(&list, &newCard)) {
		ShowNameCardInfo(newCard);
	}

	return 0;
}