#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node *next;
};

void enqueue(int num);
void dequeue();
void print();
void frontF();
void rearF();
void create();

node *front,*rear,*temp;
int count=0;

int main()
{
	int ch,num;
	create();
	cout<<"1. Enqueue"<<endl;
	cout<<"2. Dequeue"<<endl;
	cout<<"3. Front"<<endl;
	cout<<"4. Rear"<<endl;
	cout<<"5. Print"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<endl;

	while(1)
	{
		cout<<"Please enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Please Enter Data: ";
				cin>>num;
				enqueue(num);
				cout<<endl;
				break;
			case 2:
				dequeue();
				cout<<endl;
				break;
			case 3:
				frontF();
				cout<<endl;
				break;
			case 4:
				rearF();
				cout<<endl;
				break;
			case 5:
				print();
				cout<<endl;
				break;
			case 6:
				exit(0);
				cout<<"The end queue was: ";
				print();
				cout<<endl;
				break;
			default:
				cout<<"Please enter valid choice!"<<endl;
				break;
		}
	}
	return 0;
}

void create()
{
	front=NULL;
	rear=NULL;
}

void enqueue(int num)
{
	if(count==0)
	{
		front=new node();
		front->data=num;
		front->next=NULL;
		rear=front;
	}
	else
	{
		temp=new node();
		temp->data=num;
		temp->next=NULL;
		rear->next=temp;
		rear=temp;
	}
	count++;
}


void dequeue()
{
	if(count!=0)
	{
		cout<<"Dequeued element is: "<<front->data<<endl;
		temp=front->next;
		delete front;
		front=temp;
		count--;
	}
	else
		cout<<"Error: Dequeue can't be performed on empty queue!"<<endl;
}


void print()
{
	temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


void frontF()
{
	if(count!=0)
		cout<<"The front element of the queue is: "<<front->data<<endl;
	else
		cout<<"The queue is empty!!"<<endl;
}


void rearF()
{
	if(count!=0)
		cout<<"The rear element of the queue is: "<<rear->data<<endl;
	else
		cout<<"The queue is empty!!"<<endl;
}