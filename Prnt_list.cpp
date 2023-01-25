//#include <stdafx.h>

#include <iomanip>
#include <iostream>
#include <conio.h>
#include "Prnt_list.h"

using namespace std;
void print_list(Contact_List* head)
{
	//system("cls");

	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
	}
	else
	{
		Contact_List* temp = head;
		cout << "\nЭлементы списка: " << endl;

		int line_size = 21;
		int line_size2 = 79;
		for (int i = 0; i < line_size2; i++)
		{
			cout << "_";
		}
		cout << endl;
		cout << left << setw(line_size + 2) << "|  фамилия" << setw(line_size + 2) << "|  имя" << setw(16) << "|  телефон" << setw(16) << "|   Д.Р." << "|" << endl;
		for (int i = 0; i < line_size2; i++)
		{
			cout << "_";
		}
		cout << endl;
		do
		{
			//int line_size = 21;
			//cout <<setw(line_size)<<"фамилия"<<setw(line_size)<<"имя"<<setw(13)<<"телефон"<<setw(10)<<"Д.Р." <<endl;
			cout << "|  ";
			int j = 0;
			j = strlen(temp->family);
			for (int i = 0; i < j; i++)
			{

				cout << char(temp->family[i]);

			}
			for (int ii = j; ii < line_size; ii++)
			{
				if (ii == line_size - 1)
				{
					cout << "|  ";
				}
				else
				{
					cout << " ";
				}
			}
			j = 0;
			j = strlen(temp->name);
			for (int i = 0; i < j; i++)
			{
				cout << temp->name[i];
			}

			for (int ii = j; ii < line_size; ii++)
			{
				if (ii == line_size - 1)
				{
					cout << "|  ";
				}
				else
				{
					cout << " ";
				}
			}


			for (int i = 0; i < 11; i++)
			{
				int xx = temp->phone[i];
				cout << xx;
				//zz.push_back(int(xx));
			}

			cout << "  |   " << setw(4) << temp->birth_date[0] << "." << setw(2) << temp->birth_date[1] << "." << setw(2) << temp->birth_date[2] << "  |";
			cout << endl;
			temp = temp->next;


		} while (temp != head);
	}
}