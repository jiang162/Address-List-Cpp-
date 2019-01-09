/*ADD--append new address
SEA--search a existed address
DEL--delete a existed address
LIST--print all of the address
MODI (adress)--modify a existed adress*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct NODE
{
	string name;
	long long phone;

	NODE *next, *pre;
};

string com1[10] = { "ADD", "SEA", "DEL", "LIST", "MODI", "HELP", "", "", "" ,"EXIT" };//commend list
string com2[10] = { "add", "sea", "del", "list", "modi", "help", "", "", "" ,"exit" };//commend list

NODE *creat();
NODE *search(NODE *head, string dic);
NODE *add(NODE *p);
void input(NODE *input);
int item(NODE* head);
void print(NODE *p);

NODE *head = NULL;
int main()
{
	string in = "", f, str;
	NODE *p = NULL;
	NODE *temp = NULL;
	while (true)
	{
		cout << ">";
		cin >> in;

		if (in == com1[0] || in == com2[0]) //add
		{
			if (NULL == p)//empty
			{
				head = creat();
				p = head;
				input(p);
			}
			else
			{
				p = add(p);
				input(p);
			}
		}

		else if (in == com1[1] || in == com2[1]) //search
		{
			cout << "Enter the name that you want to search:" << endl;
			cout << ">";
			cin >> str;
			if ((temp = search(head, str))!= NULL)
			{
				cout << left << setw(15) << "NO." << left << setw(15) << "Name" << left << setw(15) << "Phone" << endl;
				cout << "--------------------------------------------" << endl;
				print(temp);
			}
			else
			{
				cout << "Not Found, want to creat a object called :" << str << "? (Y/N)" << endl;
				cout << ">";
				while (cin >> f)
				{
					if (f == "N" || f == "n")
						break;
					else if (f == "Y" || f == "y")
					{
						if (NULL == p)//empty
						{
							head = creat();
							p = head;
						}
						else
						{
							p = add(p);
						}
						p->name = str;
						cout << "Enter the his/her phone number" << endl << ">";
						cin >> p->phone;

						cout << "New contact:" << endl;
						print(p);

						break;
					}
					else
						cout << "invalid input, try again (Y/N)" << endl << ">";
				}
			}

		}

		else if (in == com1[2] || in == com2[2]) //delete
		{
			cout << "Enter the name of the object that you want delete" << endl;
			cout << ">";
			cin >> str;
			temp = search(head, str);
			if (NULL != temp)
			{
				cout << "REALLY? (Y/N) :";
				while (cin >> f)
				{
					if (f == "N" || f == "n")
						break;
					else if (f == "Y" || f == "y")
					{
						if (p == temp)
							p = p->pre;

						if (temp->next != NULL)
						{
							temp->pre->next = temp->next;
							temp->next->pre = temp->pre;
						}
						else if (temp == head)
						{
							head = NULL;
						}
						else
						{
							temp->pre->next = NULL;
						}
						free(temp);
						cout << "Delete success" << endl;
						break;
					}
					else
						cout << "invalid input, try again (Y/N)" << endl << ">";
				}
			}
			else
				cout << "ERROR: Object does not exist" << endl;
		}

		else if (in == com1[3] || in == com2[3]) //print
		{
			if (!item(head)) // empty
			{
				cout << "Want to creat a new adress? (Y/N)" << endl;
				cout << ">";
				while (cin >> f)
				{
					if (f == "N" || f == "n")
						break;
					else if (f == "Y" || f == "y")
					{
						head = creat();
						p = head;
						input(p);
						break;
					}
					else
						cout << "invalid input, try again (Y/N)" << endl << ">";
				}
			}
		}

		else if (in == com1[4] || in == com2[4]) //modify
		{
			cout << "Enter the name of the phone you want to change" << endl;
			cout << ">";
			cin >> str;
			if ((temp = search(head, str)) != NULL)
			{
				cout << endl;
				cout << left << setw(15) << "NO." << left << setw(15) << "Name" << left << setw(15) << "Phone" << endl;
				cout << "--------------------------------------------" << endl;
				print(temp);
				cout << "Enter the new phone number:" << endl;
				cout << ">";
				cin >> temp->phone;
				cout << "modified phone as follow" << endl;
				print(temp);
			}
		}

		else if (in == com1[5] || in == com2[5])
		{
			cout << "add--append new address" << endl;
			cout << "sea--search a existed address" << endl;
			cout << "del--delete a existed address" << endl;
			cout << "list--print all of the address" << endl;
			cout << "modi--modify a existed adress" << endl;
		}

		else if (in == com1[9] || in == com2[9])
		{
			break;
		}

		else
		{
			cout << "\"" << in << "\"" << " is NOT a commend, use \"help\" to get help" << endl;
		}
	}
	return 0;
}

void input(NODE *input)
{
	string temp;
	cout << "Input the name of the new contact" << endl << ">";
	while (cin >> temp)
	{
		if (search(head, temp))
		{
			cout << "\"" << temp << "\"" << " have existed, please tap again" << endl;
		}
		else
		{
			input->name = temp;
			break;
		}
	}
	cout << "Enter the his/her phone number" << endl << ">";
	cin >> input->phone;

	cout << "New contact:" << endl;
	print(input);
}

void print(NODE *p)
{
	cout << left << setw(15) << p->name;
	cout << left << setw(15) << p->phone << endl;

}

int item(NODE* head)
{
	int flag = 1, num = 0;
	NODE* p = head;
	if (NULL == p)
	{
		flag = 0;
		cout << "List is empty" << endl;
		return flag;
	}
	cout << left << setw(15) << "NO." << left << setw(15) << "Name" << left << setw(15) << "Phone" << endl;
	cout << "--------------------------------------------" << endl;
	while (p != NULL)
	{
		num++;
		cout << left << setw(15) << num;
		print(p);
		p = p->next;
	}

	return flag;
}

NODE *creat()
{
	NODE *head = NULL;
	head = new(NODE);
	head->next = NULL;
	head->pre = NULL;
	return head;
}

NODE *add(NODE *p)
{
	NODE *p2;
	p2 = new(NODE);
	p2->pre = p;
	p2->next = NULL;
	p->next = p2;
	p = p2;
	return p;
}

NODE *search(NODE *head, string target)
{
	NODE *p = head;
	while (p != NULL)
	{
		if (p->name == target)
			return p;
		p = p->next;
	}
	return NULL;
}