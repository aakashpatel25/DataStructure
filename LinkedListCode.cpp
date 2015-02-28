//Aakash Moghariya
//SRM University
//aakashpatel775@gmail.com
//© Copyrights Reserved.

#include<iostream>
#include<new>
using namespace std;

struct node
{
	int num;
	node *next;
};


void createList();
void insertEmpty();
void insertAtBig();
void insertAtMid();
void insertAtEnd();
void deleteAtBig();
void deleteAtMid();
void deleteAtEnd();
void emptyList();
void destroyList();
void printData();

int count=0,data,ind,i,choice,dis;
node *head,*pres,*temp,*temp1;



int main()
{
	createList();
	cout<<"\n\n--------------------LINKED LIST-------------------"<<endl;
	cout<<"1.Insert At Begining\n";
	cout<<"2.Insert At Mid \n3.Insert At End\n";
	cout<<"4.Print\n5.Delete At Begining\n6.Delete At Mid\n";
	cout<<"7.Delete At End\n8.Dstroy List\n9.Empty List\n";
	cout<<"10.Quit"<<endl;
	cout<<"\nPlease Enter Your Choice: ";
	cin>>choice;
	while(1)
	{
		switch(choice)
		{
			case 1:
				if(count==0)
				{
					insertEmpty();
				}
				else
				{
					insertAtBig();
				}
				break;
			case 2:
				if(count==0)
				{
					insertEmpty();
				}
				else
				{
					insertAtMid();
				}
				break;
			case 3:
				if(count==0)
				{
					insertEmpty();
				}
				else
				{
					insertAtEnd();
				}
				break;
			case 4:
				printData();
				break;
			case 5:
				deleteAtBig();
				break;
			case 6:
				deleteAtMid();
				break;
			case 7:
				deleteAtEnd();
				break;
			case 8:
				destroyList();
				cout<<"The List Has Been Deleted!";
				createList();
				break;
			case 9:
				emptyList();
				break;
			case 10:
				break;
			default:
				cout<<"Please Enter Valid Choice ";
				break;
		}
		if(choice==10)
		{
			break;
		}
		cout<<"\n\n";
		cout<<"\n\n--------------------LINKED LIST-------------------"<<endl;
		cout<<"1.Insert At Begining\n";
		cout<<"2.Insert At Mid \n3.Insert At End\n";
		cout<<"4.Print\n5.Delete At Begining\n6.Delete At Mid\n";
		cout<<"7.Delete At End\n8.Dstroy List\n9.Empty List\n";
		cout<<"10.Quit"<<endl;
		cout<<"\nPlease Enter Your Choice: ";
		cin>>choice;
	}
	destroyList();
	return 0;
}






void createList()
{
	head = NULL;
}



void insertEmpty()
{
	cout<<"Please Enter the Number: ";
	cin>>data;
	pres=new node;
	head = pres;
	pres->num=data;
	pres->next=NULL;
	count++;
}



void insertAtBig()
{
	temp=head;
	pres=head;
	pres=new node;
	head=pres;
	pres->next=temp;
	cout<<"Please Enter The Number: ";
	cin>>data;
	pres->num=data;
	count++;
}



void insertAtMid()
{
	while(1)
	{
		cout<<"Please Enter The Index: ";
		cin>>ind;
		if(ind>count)
		{
			cout<<"The Index Value is Greater then the List"<<endl;
			cout<<"Would You Like To Insert At End of The List?"<<endl;
			cout<<"1.Y-1\n2.N-0"<<endl;
			cout<<"Please Enter Your Choice: ";
			cin>>dis;
			if(dis==1)
			{
				insertAtEnd();
				break;
			}
			else
			{
				cout<<"Please Enter Valid Index!!!!"<<endl;
			}
		}
		else
		{
			break;
		}
	}
	pres=head;
	for(i=0;i<ind-1;i++)
	{
		pres=pres->next;
	}
	temp=pres;
	temp1=pres->next;
	pres=new node;
	temp->next=pres;
	pres->next=temp1;
	cout<<"Please Enter the Number: ";
	cin>>data;
	pres->num=data;
	count++;
}



void insertAtEnd()
{
	pres=head;
	while(pres!=NULL)
	{
		if((pres->next)!=NULL)
		{
			pres=pres->next;
		}
		else
		{
			break;
		}
	}
	cout<<"Please Enter the Number: ";
	cin>>data;
	pres->next=new node;
	pres=pres->next;
	pres->num=data;
	pres->next=NULL;
	count++;
}



void printData()
{
	pres=head;
	cout<<"\n\n----------------The List----------------"<<endl;
	if(count==0)
	{
		cout<<"The List is Empty!!"<<endl;
	}
	while(pres!=NULL)
	{
		cout<<(pres->num);
		pres = pres->next;
		if(pres!=NULL)
		{
			cout<<"->";
		}
	}
	cout<<endl;
}



void deleteAtBig()
{
	if(count==0)
	{
		cout<<"Sorry The List Is Empty And Element Can't be Deleted!"<<endl;
	}
	else
	{
		pres=head;
		head=pres->next;
		cout<<"The Deleted Element is: "<<pres->num<<endl;
		delete pres;
		count--;
	}
}



void deleteAtMid()
{
	if(count==0)
	{
		cout<<"Sorry The List Is Empty And Element Can't be Deleted!"<<endl;
	}
	else
	{
		while(1)
		{
			cout<<"Please enter the Index: ";
			cin>>ind;
			if(ind>count)
			{
				cout<<"The Index Value is Greater then the List"<<endl;
				cout<<"Please Enter Valid Index!!"<<endl;
			}
			else
			{
				break;
			}
		}
		temp=head;
		for(i=0;i<ind-1;i++)
		{
			temp=temp->next;
		}
		pres=temp->next;
		temp->next=pres->next;
		cout<<"The Deleted Element is: "<<pres->num<<endl;
		delete pres;
		count--;
	}
}



void deleteAtEnd()
{
	if(count==0)
	{
		cout<<"Sorry The List Is Empty And Element Can't be Deleted!"<<endl;
	}
	else
	{
		temp=head;
		for(i=0;i<count-2;i++)
		{
			temp=temp->next;
		}
		pres=temp->next;
		temp->next=NULL;
		cout<<"The Deleted Element is: "<<pres->num<<endl;
		delete pres;
		count--;
	}
}



void emptyList()
{
	if(count==0)
	{
		cout<<"\n\nThe List is Empty!!"<<endl;
	}
	else
	{
		cout<<"\n\nThe List is Not Empty!!"<<endl;
	}
}



void destroyList()
{
	while(head!=NULL)
	{
		pres=head;
		head=pres->next;
		delete pres;
	}
	count=0;
}
