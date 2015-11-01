/*
기능 1 , 계좌계설
기능 2 , 입금
기능 3 , 출금
기능 4 , 전체고객 잔액조회
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct form {
	int id;
	char name[20];
	int deposit;
	struct form *next;
};

// Function declare
form* select_Menu(form *sptr);
form* makeAccount();
void withdraw(form *sptr);
void deposit(form *sptr);
void printAll(form *sptr);
void exit();

int main(void)
{
	struct form *sptr = NULL;

	// 메뉴 출력
	while (true) {
		sptr = select_Menu(sptr);
	}
}

// 메뉴 선택
form* select_Menu(form *sptr) {
	int select;

	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << endl;
	cout << "선택: ";
	cin >> select;

	cout << "sptr1 Address: " << sptr << endl;
	switch (select)
	{
		case 1: 
			if (sptr == NULL)
				sptr = makeAccount();
			else
				makeAccount();
			break;
		case 2:
			deposit(sptr);
			break;
		case 3: 
			withdraw(sptr);
			break;
		case 4:
			printAll(sptr);
			break;
		case 5:
			exit();
			break;
		default :
			cout << "잘못 입력하셨습니다!" << endl;
			break;
	}
	return sptr;
}	// select_Menu();

// 계좌 생성
form* makeAccount() {
	struct form *account , *ptr = NULL , *sptr = NULL ;
	int id, deposit; 
	char name[20] = "";

	cout << "[계좌계설]" << endl;
	cout << "계좌ID :";
	cin >> id;
	cout << "이름 :";
	cin >> name;
	cout << "입금액 :";
	cin >> deposit;

	account = (form*)malloc(sizeof(form));
	// DB에 계좌가 처음생성되는 경우
	if (ptr == NULL) {
		sptr = account;
		ptr = account;
		cout << "sptr2 Address: " <<sptr << endl;
	}
	// DB에 계좌가 이미 있고 더 추가하는 경우
	else {
		while (ptr) {
			if (ptr->next == NULL)
				ptr->next = account;
			else
			{
				ptr = ptr->next;
			}
		}
	}
	account->id = id;
	cin.clear();
	strcpy_s(account->name, name);
	account->deposit = deposit;

	return sptr;
}
// 출금
void withdraw(form *sptr) {	
	int id, withdraw;

	cout << "계좌ID:";
	cin >> id;
	cout << "출금 액수: ";
	cin >> withdraw;

	while (sptr) {
		if (sptr->id != id)
			sptr = sptr->next;
		else {
			// 출금이 불가능한 경우
			if (sptr->deposit - withdraw < 0) {
				cout << "잔액이 부족하여 출금할 수 없습니다." << endl;
			}
			// 출금이 가능한 경우
			else  
				sptr->deposit -= withdraw;
			cout << "성공적으로 출금 되었습니다." << endl;
		}
	}
}
// 입금
void deposit(form *sptr) {
	int id, deposit;

	cout << "계좌ID:";
	cin >> id;
	cout << "입금 액수: ";
	cin >> deposit;

	while (sptr) {
		if (sptr->id != id)
			sptr = sptr->next;
		else {
			sptr->deposit += deposit;
			cout << "성공적으로 입금되었습니다." << endl;
		}
	}
	
}
// 계좌 전체 출력
void printAll(form *sptr) {
	
	while (sptr) {
		cout << "계좌ID: " << sptr->id << endl;
		cout << "이름: " << sptr->name << endl;
		cout << "잔액: " << sptr->deposit << endl;
		sptr = sptr->next;
	}
}
// 시스템 종료
void exit() {
	exit(1);
}