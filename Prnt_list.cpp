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
		cout << "\n������ ����\n\n";
	}
	else
	{
		Contact_List* temp = head;
		cout << "\n�������� ������: " << endl;

		int line_size = 21;
		int line_size2 = 79;
		for (int i = 0; i < line_size2; i++)
		{
			cout << "_";
		}
		cout << endl;
		cout << left << setw(line_size + 2) << "|  �������" << setw(line_size + 2) << "|  ���" << setw(16) << "|  �������" << setw(16) << "|   �.�." << "|" << endl;
		for (int i = 0; i < line_size2; i++)
		{
			cout << "_";
		}
		cout << endl;
		do
		{
			//int line_size = 21;
			//cout <<setw(line_size)<<"�������"<<setw(line_size)<<"���"<<setw(13)<<"�������"<<setw(10)<<"�.�." <<endl;
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