#pragma once
#ifndef Prnt_list
#define Prnt_list
struct Contact_List
{
	int birth_date[3] = { NULL };//информационное поле дата рождения
	int phone[11] = { NULL };//информационное поле номер телефона
	char name[20] = { NULL }; //информационное поле имя
	char family[20] = { NULL }; //информационное поле фамилия
	Contact_List* next; //указатель на следующий элемент
	Contact_List* prev; //указатель на предыдущий элемент
};

void print_list(Contact_List* head);
#endif