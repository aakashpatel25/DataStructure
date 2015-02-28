#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

void preOrder(node *rt);
void postOrder(node *rt);
void inOrder(node *rt);
node * crtNewNode(int num);

int main()
{
	node * root=crtNewNode(1);
	root->left=crtNewNode(2);
	root->left->left=crtNewNode(4);
	root->left->right=crtNewNode(5);
	root->right=crtNewNode(3 );
	postOrder(root);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	return 0;
}

node * crtNewNode(int num)
{
	 node *temp=new node();
	 temp->data=num;
	 temp->left=NULL;
	 temp->right=NULL;
	 return temp;
}

void preOrder(node *rt)
{
	if (rt==NULL)
		return;
	cout<<rt->data;
	preOrder(rt->left);
	preOrder(rt->right);
}

void postOrder(node *rt)
{
	if(rt==NULL)
		return;
	postOrder(rt->left);
	postOrder(rt->right);
	cout<<rt->data;
}

void inOrder(node *rt)
{
	if(rt==NULL)
		return;
	inOrder(rt->left);
	cout<<rt->data;
	inOrder(rt->right);
}