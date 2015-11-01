/*
��� 1 , ���°輳
��� 2 , �Ա�
��� 3 , ���
��� 4 , ��ü�� �ܾ���ȸ
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

	// �޴� ���
	while (true) {
		sptr = select_Menu(sptr);
	}
}

// �޴� ����
form* select_Menu(form *sptr) {
	int select;

	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
	cout << "����: ";
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
			cout << "�߸� �Է��ϼ̽��ϴ�!" << endl;
			break;
	}
	return sptr;
}	// select_Menu();

// ���� ����
form* makeAccount() {
	struct form *account , *ptr = NULL , *sptr = NULL ;
	int id, deposit; 
	char name[20] = "";

	cout << "[���°輳]" << endl;
	cout << "����ID :";
	cin >> id;
	cout << "�̸� :";
	cin >> name;
	cout << "�Աݾ� :";
	cin >> deposit;

	account = (form*)malloc(sizeof(form));
	// DB�� ���°� ó�������Ǵ� ���
	if (ptr == NULL) {
		sptr = account;
		ptr = account;
		cout << "sptr2 Address: " <<sptr << endl;
	}
	// DB�� ���°� �̹� �ְ� �� �߰��ϴ� ���
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
// ���
void withdraw(form *sptr) {	
	int id, withdraw;

	cout << "����ID:";
	cin >> id;
	cout << "��� �׼�: ";
	cin >> withdraw;

	while (sptr) {
		if (sptr->id != id)
			sptr = sptr->next;
		else {
			// ����� �Ұ����� ���
			if (sptr->deposit - withdraw < 0) {
				cout << "�ܾ��� �����Ͽ� ����� �� �����ϴ�." << endl;
			}
			// ����� ������ ���
			else  
				sptr->deposit -= withdraw;
			cout << "���������� ��� �Ǿ����ϴ�." << endl;
		}
	}
}
// �Ա�
void deposit(form *sptr) {
	int id, deposit;

	cout << "����ID:";
	cin >> id;
	cout << "�Ա� �׼�: ";
	cin >> deposit;

	while (sptr) {
		if (sptr->id != id)
			sptr = sptr->next;
		else {
			sptr->deposit += deposit;
			cout << "���������� �ԱݵǾ����ϴ�." << endl;
		}
	}
	
}
// ���� ��ü ���
void printAll(form *sptr) {
	
	while (sptr) {
		cout << "����ID: " << sptr->id << endl;
		cout << "�̸�: " << sptr->name << endl;
		cout << "�ܾ�: " << sptr->deposit << endl;
		sptr = sptr->next;
	}
}
// �ý��� ����
void exit() {
	exit(1);
}