#pragma once
#ifndef Prnt_list
#define Prnt_list
struct Contact_List
{
	int birth_date[3] = { NULL };//�������������� ���� ���� ��������
	int phone[11] = { NULL };//�������������� ���� ����� ��������
	char name[20] = { NULL }; //�������������� ���� ���
	char family[20] = { NULL }; //�������������� ���� �������
	Contact_List* next; //��������� �� ��������� �������
	Contact_List* prev; //��������� �� ���������� �������
};

void print_list(Contact_List* head);
#endif