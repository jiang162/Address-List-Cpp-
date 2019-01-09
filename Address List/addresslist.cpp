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

string com[10] = { "ADD", "SEA", "DEL", "LIST", "MODI"};//commend list

NODE *creat();
NODE *add(NODE *p);
void input(NODE &input);

int main()
{
	string in;
	NODE *p = NULL;
	cin >> in;
	if (in == com[0])
	{
		if (NULL == p)//empty
			p = creat();
		else add();
	}
	return 0;
}

void input(NODE &input)
{
	cout << "Input the name of the new contact" << endl << ">";
	cin >> input.name;
	cout << "Input the his/her phone number" << endl << ">";
	cin >> input.phone;
}

NODE *creat()
{
	NODE *head = NULL;
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->pre = NULL;
	return head;
}

NODE *add(NODE *p)
{

}