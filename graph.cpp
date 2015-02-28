#include<iostream>
#include<cstdlib>
using namespace std;

//This is to represent nodes of the Adjacency List.
struct node
{
	int dest;
	node *next;
};

//This is basically a pointer to head of each of the list.
struct AdjList
{
	node *head;
};

//Graph is basically collection of the adjacency lists.
struct Graph
{
	int v;
	AdjList* array;
};

node* createNode(int des);
Graph* createGraph(int ver);
void addEdge(Graph *g,int src, int des);
void printG(Graph *g);

int i,j;
node *temp,*nw;
Graph *grp;


//-----------------------------------Main Program Starts here------------------------------------
int main()
{
	int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printG(graph);
	return 0;
}


node * createNode(int des)
{
	temp=new node();
	temp->dest=des;
	temp->next=NULL;
	return temp;
}


Graph* createGraph(int ver)
{
	Graph* grp = (Graph*)malloc(sizeof(Graph));
    grp->v = ver;
    grp->array = (AdjList*)malloc(ver*sizeof(AdjList));
    for (i=0;i<ver;++i)
        grp->array[i].head = NULL;
    return grp;
}


void addEdge(Graph *g,int src,int des)
{
	nw=createNode(des);
	nw->next=g->array[src].head;
	g->array[src].head=nw;

	nw=createNode(src);
	nw->next=g->array[des].head;
	g->array[des].head=nw;
}


void printG(Graph *g)
{
	for(i=0;i<g->v;i++)
	{
		temp=g->array[i].head;
		cout<<"The Adjecency list of vertex: "<<i<<" is:"<<endl;
		cout<<"Head ";
		while(temp!=NULL)
		{
			cout<<" -> "<<temp->dest;
			temp=temp->next;
		}
		cout<<"\n"<<endl;
	}
}