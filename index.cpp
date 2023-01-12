#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
int roll;
string Name;
string Dept;
int Marks;
Node *next;
};

Node *head = new Node();

bool check(int x)
{
if (head == NULL)
return false;
Node *t = new Node;
t = head;

while (t != NULL)
{
if (t->roll == x)
return true;
t = t->next;
}
return false;
}

void Insert_Record(int roll, string Name,
string Dept, int Marks)
{

if (check(roll))
{
cout << "\n\t\t\t\t\t\t\t\t STUDENTS WITH THIS "
<< "RECORD ALREADY EXIST\n";
cout << "\t\t\t\t\t\t\t\t******"
<< "**********";
return;
}

Node *t = new Node();
t->roll = roll;

t->Name = Name;
t->Dept = Dept;
t->Marks = Marks;
t->next = NULL;

if (head == NULL || (head->roll >= t->roll))
{
t->next = head;
head = t;
}

else
{
Node *c = head;
while (c->next != NULL && c->next->roll < t->roll)
{
c = c->next;
}
t->next = c->next;
c->next = t;
}
cout << "\n \t\t\t\t\t\t\t\t\tRECORD INSERTED "
<< "SUCCESSFULLY\n";
cout << "\t\t\t\t\t\t\t\t*******"
<< "*********";
}

void Search_Record(int roll)
{

if (!head)
{
cout << "\n\t\t\t\t\t\t\t\t\t NO SUCH RECORD "
<< "AVAILABLE\n";
cout << "\t\t\t\t\t\t\t\t********"
<< "**********";
return;
}

else
{
Node *p = head;
while (p)
{
if (p->roll == roll)
{
cout << "\n\t\t\t\t\t\t\t\t\t ROLL NO. :- "
<< p->roll << endl;
cout << "\t\t\t\t\t\t\t\t\t NAME :- "
<< p->Name << endl;
cout << "\t\t\t\t\t\t\t\t\t COURSE :- "
<< p->Dept << endl;
cout << "\t\t\t\t\t\t\t\t\t MARKS :- "
<< p->Marks << endl
<< endl;
cout << "\t\t\t\t\t\t\t\t******"
<< "************";
return;
}
p = p->next;
}
if (p == NULL)
cout << "\n \t\t\t\t\t\t\t\t\t NO SUCH RECORD "
<< "AVAILABLE\n";
cout << "\t\t\t\t\t\t\t\t*********"
<< "*********";
}
}

int Delete_Record(int roll)
{
Node *t = head;
Node *p = NULL;

if (t != NULL && t->roll == roll)
{
head = t->next;
delete t;
cout << "\n\t\t\t\t\t\t\t\t\tRECORD DELETED "
<< "SUCCESSFULLY\n";
cout << "\t\t\t\t\t\t\t\t********"
<< "**********";
return 0;
}

while (t != NULL && t->roll != roll)
{
p = t;
t = t->next;
}
if (t == NULL)
{
cout << "\n\t\t\t\t\t\t\t\t\t RECORD DOES NOT EXIST\n";
cout << "\t\t\t\t\t\t\t\t**********"
<< "********";
return -1;
p->next = t->next;
delete t;
cout << "\n\t\t\t\t\t\t\t\t\tRECORD DELETED "
<< "SUCCESSFULLY\n";
cout << "\t\t\t\t\t\t\t\t**********"
<< "******";
return 0;
}
return 0;
}

void Show_Record()
{
Node *p = head;
if (p == NULL)
{
cout << "\t\t\t\t\t\t\t\t\tNO RECORD "
<< "AVAILABLE\n";
cout << "\t\t\t\t\t\t\t\t********"
<< "********";
}
else
{
cout << "\t\t\t\t\t\t\t\t\tROLL NO\tNAME\t\tCOURSE"
<< "\tMARKS\n";
cout << "\t\t\t\t\t\t\t\t\t-------\t----\t\t------"
<< "\t ----\n";

while (p != NULL)
{
cout << p->roll << " \t"
<< p->Name << "\t"
<< p->Dept << "\t"
<< p->Marks << endl;
p = p->next;
}
}
cout << "\t\t\t\t\t\t\t\t*********"
<< "*********";
}

int main()
{
head = NULL;
string Name, Course;
int Roll, Marks;
int Choice;

cout << "\n\n\t\t\t\t\t\t\t\t*******"
<< "*********\n";
cout << "\t\t\t\t\t\t\t\t*WELCOME TO STUDENTS RECORD"
<< " MANAGEMENT SYSTEM*\n";
cout << "\t\t\t\t\t\t\t\t*********"
<< "*********";
while (true)
{
cout << "\n\n\n\n\t\t\t\t\t\t\t\t\tMAIN MENU\t PRESS"
<< "\n\t\t\t\t\t\t\t\t\t****\t **"
<< "\n\n\t\t\t\t\t\t\t\t\tCREATE A NEW RECORD\t[1]"
<< "\n\t\t\t\t\t\t\t\t\tDELETE A RECORD\t\t[2]"
<< "\n\t\t\t\t\t\t\t\t\tSEARCH A STUDENT RECORD\t[3]"
<< "\n\t\t\t\t\t\t\t\t\tVIEW ALL RECORDS\t[4]"
<< "\n\t\t\t\t\t\t\t\t\tEXIT\t\t\t[5]";
cout << "\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE => ";

cin >> Choice;
if (Choice == 1)
{
cout << "\n\t\t\t\t\t\t\t\t\tENTER STUDENT'S NAME \t:- ";
getline(cin >> ws, Name);
cout << "\t\t\t\t\t\t\t\t\tENTER STUDENT'S ROLL NO :- ";
cin >> Roll;
cout << "\t\t\t\t\t\t\t\t\tENTER STUDENT'S COURSE \t:- ";
getline(cin >> ws, Course);
cout << "\t\t\t\t\t\t\t\t\tENTER STUDENT'S MARKS \t:- ";
cin >> Marks;
Insert_Record(Roll, Name, Course, Marks);
}
else if (Choice == 2)
{
cout << "\n\t\t\t\t\t\t\tENTER ROLL NUMBER OF STUDENT WHOSE "
"RECORD IS TO BE DELETED :- ";
cin >> Roll;
Delete_Record(Roll);
}
else if (Choice == 3)
{
cout << "\n\t\t\t\t\t\t\tENTER ROLL NUMBER OF STUDENT WHOSE "
"RECORD YOU WANT TO SEARCH :-";
cin >> Roll;
Search_Record(Roll);
}
else if (Choice == 4)
{
Show_Record();
}
else if (Choice == 5)
{
exit(0);
}
else
{
cout << "\t\t\t\t\t\t\t\t\tINVALID CHOICE "
<< "TRY AGAIN\n";
cout << "\t\t\t\t\t\t\t\t********"
<< "**********";
}
}
return 0;
}
