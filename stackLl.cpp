#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node *ptr;
};

void create();
void push(int no);
void pop();
void s_top();
void s_count();
void empty();
void print();
void destroy();

int count=0;
node *temp,*head;

int main()
{
	int ch,num;
	create();
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Stack Top"<<endl;
	cout<<"4. Stack Count"<<endl;
	cout<<"5. Empty"<<endl;
	cout<<"6. Print Stack"<<endl;
	cout<<"7. Destroy"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<endl;

	while(1)
	{
		cout<<"Please Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Please Enter Data: ";
				cin>>num;
				push(num);
				cout<<endl;
				break;
			case 2:
				pop();
				cout<<endl;
				break;
			case 3:
				s_top();
				cout<<endl;
				break;
			case 4:
				s_count();
				cout<<endl;
				break;
			case 5:
				empty();
				cout<<endl;
				break;
			case 6:
				print();
				cout<<endl;
				break;
			case 7:
				destroy();
				cout<<endl;
				break;
			case 8:
				cout<<"Your final Stack was: ";
				print();
				exit(0);
			default:
				cout<<"Please Enter Valid Choice!"<<endl;
				break;
		}
	}
	return 0;
}

void create()
{
	head=NULL;
	count=0;
}

void push(int num)
{
	if(count==0)
	{
		head=new node();
		head->ptr=NULL;
		head->data=num;
	}
	else
	{
		temp=new node();
		temp->data=num;
		temp->ptr=head;
		head=temp;
	}
	count++;
}

void pop()
{
	if(count!=0)
	{
		temp=head->ptr;
		cout<<"Poped element is: "<<head->data<<endl;
		delete head;
		head=temp;
		count--;
	}
	else
		cout<<"Error: Element can't be popped! Stack is empty!!!"<<endl;
}


void print()
{
	if(count!=0)
	{
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->ptr;
		}
		cout<<endl;
	}
	else
		cout<<"The stack is empty!!"<<endl;
}


void s_top()
{
	if(count!=0)
		cout<<"The element at the top of the Stakc is: "<<head->data<<endl;
	else
		cout<<"The stack is empty!!!"<<endl;
}


void s_count()
{
	cout<<"Number of elements in stack is: "<<count<<endl;
}


void empty()
{
	if(count==0)
		cout<<"Yep, the Stack is empty!!"<<endl;
	else
		cout<<"The Stack contains "<<count<<" elements!!!"<<endl;
}


void destroy()
{
	if(count!=0)
	{
		temp=head->ptr;
		while(temp!=NULL)
		{
			delete head;
			head=temp;
			temp=head->ptr;	
		}
		delete head;
		head=temp;
		count=0;
		cout<<"The stack has been destroyed!!!"<<endl;
	}
	else
		cout<<"Error: Stack Empty!!!"<<endl;
}