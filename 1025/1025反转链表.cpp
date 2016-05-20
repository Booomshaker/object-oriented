#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
struct Node
{
	int Address;
	int Data;
	int Next;
	Node *next;
};

Node* ReverseList(Node *head,int m)
{
	Node *p,*q,*r;
	p = head;
	q = p->next;
	for(int i = 0;i < m-1;i++)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = q;
	return p;	
}

int main()
{
	
	int input_Data[100005],input_Next[100005];
	int first,n,k,t;
	cin >> first >> n >> k;
	int a,b,c;
	for(int i = 0;i < n;i++)
	{
		cin >> a >> b >> c;
		input_Data[a] = b;
		input_Next[a] = c;
	}
	
	Node *p1,*p2,*head,*f;
	p2 = new Node;
	t = first;
	for(int i = 0;i < n;i++)
	{
		p1 = new Node;
		p1->Address = t;
		p1->Data = input_Data[t];
		p1->Next = input_Next[t];
		if(i == 0)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		if(i != n-1)		
			t = input_Next[t];		
	}
	p2->next = NULL;
	//创建链表 
	
	
	
	Node *p = head,*p3,*p4;
	
	for(int j = 0,X = 0;j < n/k;j++,X++)
	{
		p = ReverseList(p,k);
		
		if(X == 0)
			f = p;
		if(j != n/k-1)
		{
			p3 = p;
			p4 = p;
			for(int w=0;w < k;w++)
				p = p->next;
			for(int w=0;w < k-1;w++)
				p3=p3->next;
			
			for(int w=0;w < k*2-1;w++)
				p4=p4->next; 
			p3->next = p4;			
		}			
	}
	p = f;
	//p3,p4和p的后移指令的先后顺序一定要搞清楚！！！！！！！！！ 	
	
	Node *temp;
	while(p)
	{
		temp = p->next;
		if(temp == NULL)
		{
			p->Next = -1;
			break;
		}
		p->Next = temp->Address;
		p = p->next;
	}
	p = f;
	while(p)
	{
		if(p->Next != -1)
			printf("%05d %d %05d\n",p->Address,p->Data,p->Next);
		else
			printf("%05d %d %d\n",p->Address,p->Data,p->Next);
		p = p->next;
	}
	
	return 0;	
}

