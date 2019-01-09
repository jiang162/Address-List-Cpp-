/*ADD--append new address
SEA--search a existed address
DEL--delete a existed address
LIST--print all of the address
MODI (adress)--modify a existed adress*/

#include <iostream>
#include <string>

using namespace std;

struct NODE
{
	string name;
	long long phone;

	NODE *next, *pre;
};

string com1[10] = { "ADD", "SEA", "DEL", "LIST", "MODI", "", "", "", "" ,"EXIT" };//commend list
string com2[10] = { "add", "sea", "del", "list", "modi", "", "", "", "" ,"exit" };//commend list

NODE *creat();
void add(NODE *p);
void input(NODE *input);
int item(NODE* head);
void print(NODE *p);


int main()
{
	string in = "", f;
	NODE *p = NULL;
	NODE *head = NULL;

	while (true)
	{
		cout << ">";
		cin >> in;
		
		if (in == com1[0] || in == com2[0])
		{
			if (NULL == p)//empty
			{
				head = creat();
				p = head;
				input(p);
			}
			else
			{
				add(p);
			}
		}
		else if (in == com1[3] || in == com2[3])
		{
			if (!item(head))
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
		else if (in == com1[9] || in == com2[9]) break;
		else
		{
			cout << "\"" << in << "\"" << " is NOT a commend, try again" << endl;
		}
	}
	return 0;
}

void input(NODE *input)
{
	cout << "Input the name of the new contact" << endl << ">";
	cin >> input->name;
	cout << "Input the his/her phone number" << endl << ">";
	cin >> input->phone;

	cout << "New contact:" << endl;
	print(input);
}

void print(NODE *p)
{

	cout << "Name:\t" << p->name << endl;
	cout << "Phone:\t" << p->phone << endl;

}

void add(NODE *p)
{
	NODE *p2;
	p2 = new(NODE);
	p2->pre = p;
	p2->next = NULL;
	p->next = p2;
	input(p2);
	p = p2;
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
	cout << "------------" << endl;
	while (p != NULL)
	{
		num++;
		cout << "No." << num << endl;
		print(p);
		cout << endl;
		p = p->next;
	}
	cout << "------------" << endl;
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