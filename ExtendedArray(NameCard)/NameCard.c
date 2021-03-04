#define _CRT_SECURE_NO_WARNINGS_
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* nameCard = (NameCard*)malloc(sizeof(NameCard)); // 구조체 동적할당
	strcpy(nameCard->name, name);
	strcpy(nameCard->phone, phone);//구조체 초기화
	
	return nameCard; //구조체 주소 반환
}

//구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pcard) {
	printf("이름: %s  전화번호: %s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard* pcard, char* name) {
	if (strcmp(pcard->name, name)==0) {
		return 0;
	}
	return 1;
}

void ChangePhoneNum(NameCard* pcard, char* phone) {
	strcpy(pcard->phone, phone);
}