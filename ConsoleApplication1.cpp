#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <fstream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include "Prnt_list.h"

using namespace std;
/*
struct Contact_List
{
	int birth_date[3] = { NULL };//�������������� ���� ���� ��������
	int phone[11] = { NULL };//�������������� ���� ����� ��������
	char name[20] = { NULL }; //�������������� ���� ���
	char family[20] = { NULL }; //�������������� ���� �������
	Contact_List* next; //��������� �� ��������� �������
	Contact_List* prev; //��������� �� ���������� �������
};
*/


Contact_List* head;

struct load_struct
{
	int birth_date[3] = { NULL };//�������������� ���� ���� ��������
	int phone[11] = { NULL };//�������������� ���� ����� ��������
	char name[20] = { NULL }; //�������������� ���� ���
	char family[20] = { NULL }; //�������������� ���� �������	
};

void my_shaker();
//void print_list();
void del_node(const char* family_d,const char* name_d);
void add_list(const int size);
void add_node();
int load_node_backup(const char* node_beta);
void load_node2(const char* node_beta);
void find_element(const int redact, const char* family, const char* name);

//���� ��������
bool is_string_correct(const char* tested);
bool is_phone_correct(const int* tested);
bool is_date_correct(const int* tested);
bool is_unique(const Contact_List* tested);
bool find_family(const char* searched);//���������� ���� ��������� � ������ ���� �������

//���� �����-������
int int_input();
int* phone_input();
int* birth_date_input();
int load_list();
int save_list();


int main()
{
	setlocale(LC_ALL, "russian");
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	bool stopper = false;
	while (!stopper)
	{
		int size = 0;
		int i = 0;
		setlocale(LC_ALL, "rus");
		cout << "\n�������� �������� ��������:\n1.����� ��������\n2.������������� �������\n3.�������� �������\n4.������� �������\n5.���������� ������\n6.����� ������\n7.���������� ������\n8.�������� ������\n0.��� ����������\n";
		int x = 0;
		while (x < 48 || x>56)
		{
			x = _getch();
			if (x < 48 || x>56)
			{
				cout << "\n������� ������������ ��������, ������� ����������\n";
			}
		}
		switch (x)
		{
		case 49://����� ��������
		{
			char test_fam[20] = { NULL };
			char test_nam[20] = { NULL };
			cout << "\n������� �������\n";
			cin >> test_fam;
			while (!cin.good() || !is_string_correct(test_fam)) //�������� ������������ �������� ��������
			{
				cin.clear();
				cin.ignore();
				cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
				cout << endl << "������� �������� ";
				cin >> test_fam;
			}
			if (!find_family(test_fam))
			{
				cout << endl << "�� ������� ����� ������� � ������" << endl;
			}
			else
			{
				cout << "\n������� ���\n";
				cin >> test_nam;
				while (!cin.good() || !is_string_correct(test_nam)) //�������� ������������ �������� ��������
				{
					cin.clear();
					cin.ignore();
					cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
					cout << endl << "������� �������� ";
					cin >> test_nam;
				}
				find_element(0, test_fam, test_nam);
			}
			break;
		}
		case 50://������������� �������
		{
			char test_fam[20] = { NULL };
			char test_nam[20] = { NULL };
			cout << "\n������� ������� �������������� ��������\n";
			cin >> test_fam;
			while (!cin.good() || !is_string_correct(test_fam)) //�������� ������������ �������� ��������
			{
				cin.clear();
				cin.ignore();
				cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
				cout << endl << "������� �������� ";
				cin >> test_fam;
			}
			if (!find_family(test_fam))
			{
				cout << endl << "�� ������� ����� ������� � ������, �� �������� �� �������������" << endl;
			}
			else
			{
				cout << "\n������� ��� �������������� ��������\n";
				cin >> test_nam;
				while (!cin.good() || !is_string_correct(test_nam)) //�������� ������������ �������� ��������
				{
					cin.clear();
					cin.ignore();
					cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
					cout << endl << "������� �������� ";
					cin >> test_nam;
				}
				find_element(1, test_fam, test_nam);
			}
			break;
		}
		case 51://�������� �������
		{
			cout << "\n������� �������� ��������\n";
			add_node();
			break;
		}
		case 52://������� �������
		{
			
			char family_d[20] = { NULL };
			char name_d[20] = { NULL };
			cout << "\n������� ������� ���������� ��������\n";
			cin >> family_d;
			while (!cin.good() || !is_string_correct(family_d)) //�������� ������������ �������� ��������
			{
				cin.clear();
				cin.ignore();
				cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
				cout << endl << "������� �������� ";
				cin >> family_d;
			}

			cout << "\n������� ��� ���������� ��������\n";
			cin >> name_d;
			while (!cin.good() || !is_string_correct(name_d)) //�������� ������������ �������� ��������
			{
				cin.clear();
				cin.ignore();
				cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
				cout << endl << "������� �������� ";
				cin >> name_d;
			}
			
			//memcpy(deleting->family, family, 20);
			//memcpy(deleting->name, name, 20);
			del_node(family_d,name_d);
			break;
		}
		case 53://���������� ������
		{
			int* temp = new int[2];
			temp[0] = 0;
			temp[1] = 0;
			my_shaker();
			//cout << "\n���������� ��������� = " << temp[0] << endl;
			//cout << "\n���������� ������������ = " << temp[1] << endl;
			break;
		}
		case 54://����� ������
		{
			print_list(head);
			break;
		}
		case 55://���������� � ���� ������
		{
			save_list();
			break;
		}
		case 56://�������� �� ����� ������
		{
			load_list();
			break;
		}
		case 48:
		{
			stopper = true;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

bool find_family(const char* searched)//���������� ���� ��������� � ������ ���� �������
{
	bool find = false;
	if (head == NULL)
	{
		cout << "\n������ ����\n";
		return false;
	}
	else
	{
		Contact_List* temp = head;
		do
		{
			int x = 0;
			for (int i = 0; i < strlen(searched); i++)
			{
				if (temp->family[i] == searched[i])
				{
					x++;
				}
			}
			if (x == strlen(searched))
				find = true;
			temp = temp->next;
		} while (temp != head);


		return find;
	}
}

void find_element(const int redact, const char* family, const char* name)
{
	bool sovpad = true;
	if (head == NULL)
	{
		cout << endl << "���� ��� ������, ������ ����" << endl;
	}
	else
	{
		Contact_List* temp = new Contact_List;
		temp = head;
		do
		{
			sovpad = true;
			for (int i = 0; i < strlen(family); i++)
			{
				if (temp->family[i] != family[i])
				{
					sovpad = false;
				}
			}
			for (int i = 0; i < strlen(name); i++)
			{
				if (temp->name[i] != name[i])
				{
					sovpad = false;
				}
			}

			if (redact == 0 && sovpad == true)
			{
				cout << "\n����� ������� ����������� � ������\n";
				break;
			}
			else if (redact == 1 && sovpad == true)
			{
				Contact_List* new_elem = new Contact_List;
				char new_fam[20] = { NULL };
				char new_nam[20] = { NULL };
				cout << "\n������� ����� �������\n";
				cin >> new_fam;
				while (!cin.good() || !is_string_correct(new_fam)) //�������� ������������ �������� ��������
				{
					cin.clear();
					cin.ignore();
					cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
					cout << endl << "������� �������� ";
					cin >> new_fam;
				}
				cout << "\n������� ����� ���\n";
				cin >> new_nam;
				while (!cin.good() || !is_string_correct(new_nam)) //�������� ������������ �������� ��������
				{
					cin.clear();
					cin.ignore();
					cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
					cout << endl << "������� �������� ";
					cin >> new_nam;
				}
				memcpy(new_elem->family, new_fam, strlen(new_fam));
				memcpy(new_elem->name, new_nam, strlen(new_nam));
				bool sovp = true;
				int len = 0;
				len = strlen(temp->family);
				for (int i = 0; i < len; i++)
				{
					if (temp->family[i] != new_elem->family[i])
					{
						sovp = false;
					}
				}

				len = strlen(temp->name);
				for (int i = 0; i < len; i++)
				{
					if (temp->name[i] != new_elem->name[i])
					{
						sovp = false;
					}
				}


				if (is_unique(new_elem)||sovp)
				{
					int* phone_n = new int[11];
					phone_n = phone_input();
					cout << "\n������� ���� ��������\n";
					int* birth_date = new int[3];
					birth_date = birth_date_input();
					cout << endl;
					for (int it = 0; it < 11; it++)
					{
						temp->phone[it]= phone_n[it];
					}
					//memcpy(temp->phone, phone_n, sizeof(phone_n));
					memcpy(temp->birth_date, birth_date, sizeof(birth_date));
					memcpy(temp->family, new_fam, strlen(new_fam));
					memcpy(temp->name, new_nam, strlen(new_nam));
				}
				else
				{
					cout << "\n������� ��������, ����������� ��������� �������\n";
				}
			}
			temp = temp->next;
		} while (temp != head);
	}
}

bool is_unique(const Contact_List* tested)
{
	bool is_correct = true;
	if (head != NULL)
	{
		Contact_List* ttemp = head;
		do
		{
			int aaa = 0;
			int bbb = 0;
			for (int tt = 0; tt < strlen(tested->name); tt++)
			{
				if (ttemp->name[tt] == tested->name[tt])
				{
					aaa++;
				}
			}
			for (int tt = 0; tt < strlen(tested->family); tt++)
			{
				if (ttemp->family[tt] == tested->family[tt])
				{
					bbb++;
				}
			}
			if (aaa == strlen(tested->name) && bbb == strlen(tested->family))
			{
				is_correct = false;
			}
			ttemp = ttemp->next;
		} while (ttemp != head);
	}
	return is_correct;
}

int load_list()
{
	int amount_errors = 0;
	char str[60] = { NULL };
	ifstream fin;// ������ ������ ifstream
	fin.open("Contact_list.csv"); // ��������� ������ � ������
	if (!fin)
	{
		cout << "�� �������� ���� ��� ������ ������";
	}
	else
	{
		while (!fin.eof())
		{
			fin.getline(str, 60);
			for (int i = 0; i < strlen(str); i++)
				cout << str[i];
			load_node2(str);
			cin.sync();
		}
		fin.close(); // ��������� ����
	}
	return amount_errors;
}

int save_list()
{
	int x = 0;
	ofstream fout;// ������ ������ ofstream
	fout.open("Contact_list.csv"); // ��������� ������ � ������
	if (!fout)
	{
		cout << "�� ������� ����, ������� �� � �������";
	}
	else
	{
		Contact_List* temp = head;
		if (head == NULL)
		{
			cout << "\n������ ����\n\n";
		}
		else
		{
			do
			{
				fout << temp->family;
				fout << ";";
				fout << temp->name;
				fout << ";";
				for (int i = 0; i < 11; i++)
				{
					fout << temp->phone[i];
				}
				fout << ";";
				fout << temp->birth_date[0];
				fout << ".";
				fout << temp->birth_date[1];
				fout << ".";
				fout << temp->birth_date[2];
				fout << "\n";
				temp = temp->next;
			} while (temp != head);
		}
		fout.close(); // ��������� ����
	}
	return x;
}

void load_node2(const char* node_beta)
{
	int birth_date[3] = { NULL };
	int phone[11] = { NULL };
	char family_beta[20] = { NULL };
	char name_beta[20] = { NULL };
	int family_end = 0;
	int name_end = 0;
	int phone_end = 0;
	int string_end = strlen(node_beta);// 1 + static_cast<int>(node_beta[0]);

	for (int j = 1; j < string_end; j++)//���� �������� ���� ������� ����������� ����� ��������� �������, �� �������� � ���, 
	{									//��� � ������� ������� �������� ���������� � ����� ������, ������� ���� �� 1 � �� �� 0

		if (node_beta[j] == ';' && family_end == 0)
		{
			family_end = j;
		}
		if (node_beta[j] == ';' && j != family_end && family_end != 0 && name_end == 0)
		{
			name_end = j;
		}
		if (node_beta[j] == ';' && j != family_end && name_end != 0 && name_end != j && phone_end == 0)
		{
			phone_end = j;
		}
	}

	int family_len = family_end;
	int name_len = name_end - family_end;
	int phone_len = phone_end - name_end;

	/***************************************��� ��������� �������*****************************************************/
	for (int ii = 0; ii < family_len; ii++)//��������� ������� � ��������� ������, �������� � �������, ��� � ������� ��� ������ ������
	{
		family_beta[ii] = node_beta[ii];
	}
	/***************************************��� ��������� �����*****************************************************/
	for (int ii = family_end + 1; ii < name_end; ii++)//��������� ����� � ��������� ������
	{
		name_beta[ii - family_end - 1] = node_beta[ii];
	}
	/***************************************��� ��������� ��������*****************************************************/
	//cout << endl << endl << "������ ���������";
	int smesh = name_end + 1;
	int stopper = 0;
	while (stopper < 11)
	{
		//cout << node_beta[stopper + smesh];
		phone[stopper] = node_beta[stopper + smesh] - 48;
		stopper++;
	}
	cout << endl << endl;
	if (!is_phone_correct(phone))
	{
		for (int tr = 0; tr < 11; tr++)
		{
			phone[tr] = 0;
		}
	}

	/***************************************��������� ���� �������� � ��������� ������******************************************/
	int ss = 0;
	int ww = 1;
	for (int ii = string_end - 1; ii > phone_end; ii--)//��������� ���� �������� � ��������� ������
	{
		if (node_beta[ii] == '.')//��� ������� ��������� �� ���� � ������ � �� ������ �� ���
		{
			ii--;
			ss++;
			ww = 1;
		}
		/***************************************��� ��������� ����*****************************************************/
		if (ss == 0)
		{
			birth_date[2] += ((node_beta[ii] - 48) * ww);
			ww = ww * 10;
		}
		/***************************************��� ��������� ������*****************************************************/
		else if (ss == 1)//��� ��������� ������
		{
			birth_date[1] += ((node_beta[ii] - 48) * ww);
			ww = ww * 10;
		}
		/***************************************��� ��������� ���*****************************************************/
		else if (ss == 2)//��� ��������� ���
		{
			birth_date[0] += ((node_beta[ii] - 48) * ww);
			ww = ww * 10;
		}
	}

	if (!is_string_correct(family_beta))
	{
		family_beta[0] = '99';		family_beta[1] = '�';		family_beta[2] = '�';		family_beta[3] = '�';		family_beta[4] = '�';		family_beta[5] = '�';		family_beta[6] = '�';
	}

	if (!is_string_correct(name_beta))
	{
		name_beta[0] = '99';		name_beta[1] = '�';		name_beta[2] = '�';		name_beta[3] = '�';		name_beta[4] = '�';		name_beta[5] = '�';		name_beta[6] = '�';
	}

	/*************************************��� �������� ������ ��������********************************************/
	Contact_List* Node = new Contact_List;

	for (int i = 0; i < strlen(family_beta); i++)
	{
		Node->family[i] = family_beta[i];
	}
	for (int i = 0; i < strlen(name_beta); i++)
	{
		Node->name[i] = name_beta[i];
	}
	for (int i = 0; i < 11; i++)
	{
		Node->phone[i] = phone[i];
	}

	if (is_unique(Node) && is_string_correct(family_beta) && is_string_correct(name_beta))
	{
		for (int i = 0; i < strlen(family_beta); i++)
		{
			Node->family[i] = family_beta[i];
		}

		if (is_date_correct(birth_date))//���������� ���� ��������
		{
			Node->birth_date[0] = birth_date[0];//
			Node->birth_date[1] = birth_date[1];//���������� ���� ��������
			Node->birth_date[2] = birth_date[2];//
		}
		else
		{
			Node->birth_date[0] = 0;//
			Node->birth_date[1] = 0;//���������� ���� ��������
			Node->birth_date[2] = 0;//
		}

		if (head == NULL) //���� ������ ����
		{
			//cout << "�������, ����� ������ �����";
			Node->next = Node; //��������� ��������� next
			Node->prev = Node; //��������� ��������� prev
			head = Node; //������������ ������ ������
		}
		else
		{
			Contact_List* p = head;
			p = p->prev;
			p->next->prev = Node;
			Node->next = p->next;
			Node->prev = p;
			p->next = Node;
		}
	}
}

void add_node()
{
	Contact_List* Node = new Contact_List; //�������� ������ ��������
	bool unique = false;
	char family[20] = { NULL };
	int fam[20] = { NULL };
	char name[20] = { NULL };
	int nam[20] = { NULL };

	cout << "\n������� �������\n";
	cin >> family;
	while (!cin.good() || !is_string_correct(family)) //�������� ������������ �������� ��������
	{
		cin.clear();
		cin.ignore();
		cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
		cout << endl << "������� �������� ";
		cin >> family;
	}
	cout << "\n������� ���\n";
	cin >> name;
	while (!cin.good() || !is_string_correct(name)) //�������� ������������ �������� ��������
	{
		cin.clear();
		cin.ignore();
		cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
		cout << endl << "������� �������� ";
		cin >> name;

	}
	memcpy(Node->family, family, 20);
	memcpy(Node->name, name, 20);
	if (is_unique(Node))
	{
		int* phone = new int[11];
		phone = phone_input();
		cout << "\n������� ���� ��������\n";
		int* birth_date = new int[3];
		birth_date = birth_date_input();

		for (int i = 0; i < 11; i++)
		{
			Node->phone[i] = phone[i]; //���������� ��������
		}
		Node->birth_date[0] = birth_date[0]; //���������� ���� ��������
		Node->birth_date[1] = birth_date[1];
		Node->birth_date[2] = birth_date[2];

		if (head == NULL) //���� ������ ����
		{
			Node->next = Node; //��������� ��������� next
			Node->prev = Node; //��������� ��������� prev
			head = Node; //������������ ������ ������
		}
		else
		{
			Contact_List* p = head;
			p = p->prev;
			p->next->prev = Node;
			Node->next = p->next;
			Node->prev = p;
			p->next = Node;
		}
	}
	else
	{
		cout << "����������� ������ �������, ������ ������ �� ���������� ���������";
	}
}

/*
void print_list()
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
*/

void del_node(const char*family_d,const char* name_d)//������� ������ � ���������� ������ � ��������
{
	int deleted=0;
	if (head == NULL)
	{
		cout << "\n������ ����\n\n";
	}
	else
	{
		Contact_List* temp = head;		
		do
		{
			bool sovpad = true;
			int length_f = 0;
			int length_n = 0;
			if (strlen(family_d) != strlen(temp->family)|| strlen(name_d) != strlen(temp->name))
			{
				//cout << endl << "�� ������ ����� �������";
			}
			else
			{
				length_f = strlen(family_d);
				for (int i = 0; i < length_f; i++)
				{
					if (family_d[i] != temp->family[i])
					{
						sovpad = false;
					}
				}
				length_n = strlen(name_d);
				for (int i = 0; i < length_f; i++)
				{
					if (name_d[i] != temp->name[i])
					{
						sovpad = false;
					}
				}
				if (!sovpad)
				{
					cout << endl << "�� ������ ����� �������";
				}
				else
				{
					deleted++;
					cout << "\n������� ������\n";
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}




			}




			

			temp = temp->next;
		} while (temp != head);
	}
	if (deleted == 0)
	{
		cout << "\n�� ������ ����� �������\n";
	}
}

//temp->prev->next = temp->next;
//temp->next->prev = temp->prev;

int int_input()
{
	int temp = 0;
	cin >> temp;
	while (!cin.good()) //�������� ������������ �������� ��������
	{
		cin.clear();
		cin.ignore();
		cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
		cout << endl << "������� �������� ";
		cin >> temp;
	}
	return temp;
}

int* phone_input()
{
	int* temp = new int[11];
	bool correct = true;
	do//�������� ������������ �������� ��������
	{
		correct = true;
		cout << "������� ������� �� ����� 8??????????";
		for (int i = 0; i < 11; i++)
		{
			int a = _getch();
			//cout << a;
			temp[i] = a - 48;
			cout << temp[i];
		}
		if (temp[0] != 8)
		{
			correct = false;
			cout << "\n������� �� ������������� �����\n";
		}


		for (int i = 1; i < 11; i++)
		{

			if (temp[i] < 0 || temp[i]>9)
			{
				cout << "\n������� �� ������������� �����\n";
				correct = false;
			}
		}
	} while (correct == false);
	return temp;
}

int* birth_date_input()
{
	int* temp = new int[3];
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cout << endl << "������� ���, �� 1920 �� 2021" << endl;
			temp[0] = int_input();
			while (temp[0] < 1920 || temp[0]>2021) //�������� ������������ �������� ��������
			{
				cout << endl << "������ ������������ ���, ������� ����������, �� 1920 �� 2021" << endl;
				temp[0] = int_input();
			}
		}
		else if (i == 1)
		{
			cout << endl << "������� �����, �� 1 �� 12" << endl;
			temp[1] = int_input();
			while (temp[1] < 1 || temp[1]>12) //�������� ������������ �������� ��������
			{
				cout << endl << "������ ������������ �����, ������� ����������, �� 1 �� 12" << endl;
				temp[1] = int_input();
			}
		}
		else if (i == 2)
		{

			int day_limit = 0;
			if (temp[1] == 2 && temp[0] % 4 == 0)
			{
				day_limit = 29;
				//cout << endl << "29";
			}
			else if (temp[1] == 2 && temp[0] % 4 != 0)
			{
				day_limit = 28;
				//cout << endl << "28";
			}
			else if (temp[1] == 1)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 3)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 4)
			{
				day_limit = 30;
				//cout << endl << "31";
			}
			else if (temp[1] == 5)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 6)
			{
				day_limit = 30;
				//cout << endl << "30";
			}
			else if (temp[1] == 7)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 8)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 9)
			{
				day_limit = 30;
				//cout << endl << "30";
			}
			else if (temp[1] == 12)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 10)
			{
				day_limit = 31;
				//cout << endl << "31";
			}
			else if (temp[1] == 11)
			{
				day_limit = 30;
				//cout << endl << "30";
			}

			cout << endl << "������� ����, �� 1 �� " << day_limit << endl;
			temp[2] = int_input();

			while (temp[2] < 1 || temp[2]>day_limit) //�������� ������������ �������� ��������
			{
				cout << endl << "������ ������������ ����, ������� ����������, �� 1 �� " << day_limit << endl;
				temp[2] = int_input();
			}
		}
		cout << temp[i];
	}

	//} while (correct == false);
	return temp;
}

bool is_string_correct(const char* tested_string)
{
	bool is_correct = true;
	int amount_of_uncorrect = 0;
	for (int i = 0; i < strlen(tested_string); i++)
	{
		int x = static_cast<int>(tested_string[i]);
		//cout << endl << x;
		if (x < -64 || x > -1)
		{
			amount_of_uncorrect++;
		}
	}

	if (amount_of_uncorrect > 0)
	{
		is_correct = false;
	}
	//cout << "\n\n �������� �������� ���������� " << is_correct << "\n\n";
	return is_correct;
}

bool is_date_correct(const int* tested)
{
	bool is_correct = true;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			if (tested[0] < 1920 || tested[0]>2021) //�������� ������������ �������� ��������
			{
				is_correct = false;
			}
		}
		else if (i == 1)
		{
			if (tested[1] < 1 || tested[1]>12) //�������� ������������ �������� ��������
			{
				is_correct = false;
			}
		}
		else if (i == 2)
		{
			int day_limit = 0;
			if (tested[1] == 2 && tested[0] % 4 == 0)
			{
				day_limit = 29;
			}
			else if (tested[1] == 2 && tested[0] % 4 != 0)
			{
				day_limit = 28;
			}
			else if (tested[1] == 1)
			{
				day_limit = 31;
			}
			else if (tested[1] == 3)
			{
				day_limit = 31;
			}
			else if (tested[1] == 4)
			{
				day_limit = 30;
			}
			else if (tested[1] == 5)
			{
				day_limit = 31;
			}
			else if (tested[1] == 6)
			{
				day_limit = 30;
			}
			else if (tested[1] == 7)
			{
				day_limit = 31;
			}
			else if (tested[1] == 8)
			{
				day_limit = 31;
			}
			else if (tested[1] == 9)
			{
				day_limit = 30;
			}
			else if (tested[1] == 12)
			{
				day_limit = 31;
			}
			else if (tested[1] == 10)
			{
				day_limit = 31;
			}
			else if (tested[1] == 11)
			{
				day_limit = 30;
			}

			if (tested[2] < 1 || tested[2]>day_limit) //�������� ������������ �������� ��������
			{
				is_correct = false;
			}
		}
	}
	return is_correct;
}

bool is_phone_correct(const int* tested)
{
	bool is_correct = true;
	if (tested[0] != 8)
	{
		is_correct = false;
	}
	for (int i = 1; i < 11; i++)
	{
		if (tested[i] < 0 || tested[i] > 9)
		{
			is_correct = false;
		}
	}
	return is_correct;
}

void my_shaker()
{
	Contact_List* temp = new Contact_List;
	temp = head;
	int amount_of_elements = 0;
	do
	{
		amount_of_elements++;
		temp = temp->next;
	} while (temp != head);

	for (int i = 0; i < pow(amount_of_elements, 2); i++)
	{
		temp = head;
		do
		{
			int length = 0;
			bool blocker = false;
			if (strlen(temp->family) > strlen(temp->next->family))
			{
				length = strlen(temp->next->family);
			}


			if (temp->family[0] > temp->next->family[0])
			{
				swap(temp->family, temp->next->family);
				swap(temp->name, temp->next->name);
				swap(temp->phone, temp->next->phone);
				swap(temp->birth_date, temp->next->birth_date);
			}
			if (temp->family[0] == temp->next->family[0] && (temp->family[1] > temp->next->family[1]))
			{
				swap(temp->family, temp->next->family);
				swap(temp->name, temp->next->name);
				swap(temp->phone, temp->next->phone);
				swap(temp->birth_date, temp->next->birth_date);
			}



			temp = temp->next;
		} while (temp->next != head);
	}
}

