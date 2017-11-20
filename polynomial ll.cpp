#include<iostream>
using namespace std;

struct llist
{
	float coeff;
	int deg;
	struct llist* link;
}*head1=NULL,*head2=NULL;
struct llist* insert(struct llist* head,int d)
{
	int c,pow=d;
	struct llist* curr=NULL,*start=NULL,*ptr=NULL;
	for(int i=1;i<=d+1;i++)
	{
		cout<<"Enter value of coefficient for degree "<<pow<<": ";
		cin>>c;
		ptr=new llist;
		ptr->deg=pow;
		ptr->coeff=c;
		ptr->link=NULL;
		if(start==NULL)
		{
			start=ptr;
			curr=ptr;
		}
		else
		{
			curr->link=ptr;
			curr=ptr;
		}
		pow--;
	}
	head=start;
	return head;
}
void printlist(struct llist* start,int d)
{
	struct llist * curr;
	curr=start;
/*	for(int i=1;i<=d+1;i++)
	{
		cout<<curr->coeff;
		if(i==d+1)
			cout<<"x^"<<curr->deg;
		else
			cout<<"x^"<<curr->deg<<"+";
	}*/
	while(curr!=NULL)
	{
		if(curr->link==NULL)
			cout<<curr->coeff;
		else
			cout<<curr->coeff<<"x^"<<curr->deg<<"+";
		curr=curr->link;
	}
}
void sum(int dif,int ldeg,struct llist* h1,struct llist* h2)
{
	int i;
	float sumcoeff=0,sumdeg;
	struct llist* ptr1=NULL,*ptr2=NULL,*start=NULL,*ptr=NULL,*curr=NULL;
	ptr1=h1;
	ptr2=h2;
	for(i=1;i<=dif;i++)
		ptr1=ptr1->link;
	cout<<endl<<"Sum is: ";
	for(i=1;i<=ldeg+1;i++)
	{
		if(i<=dif)
		{
			cout<<h1->coeff<<"x^"<<h1->deg<<"+";
			h1=h1->link;
		}
		else if(dif==0)
		{
			sumcoeff=ptr1->coeff+ptr2->coeff;
			if(i==ldeg+1)
				cout<<sumcoeff;
			else
				cout<<sumcoeff<<"x^"<<ptr1->deg<<"+";
			sumcoeff=0;	
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else
		{
			sumcoeff=ptr1->coeff+ptr2->coeff;
			if(i==ldeg+1)
				cout<<sumcoeff;
			else
				cout<<sumcoeff<<"x^"<<ptr1->deg<<"+";
			sumcoeff=0;	
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
	}
}
void product(int d1,int d2,struct llist* h1,struct llist* h2)
{
	int i;
	struct llist* prod_head=NULL,*curr=NULL,*ptr=NULL,*l1,*l2,*start;
	l1=h1;
	l2=h2;
	
	while(l1!=NULL)
	{
		l2=h2;
		while(l2!=NULL)
		{
			ptr->coeff=l1->coeff*l2->coeff;
			ptr->deg=l1->deg+l2->deg;
			if(prod_head==NULL)
			{
				prod_head=ptr;
				curr=ptr;
			}
			else
			{
				curr->link=ptr;
				curr=ptr;
			}
			l2=l2->link;
		}
		l1=l1->link;
	}
	
	
}
int main()
{
	struct llist* head=NULL,*start=NULL;
	int deg1,deg2,diff;
	cout<<"Enter degree of polynomial 1: ";
	cin>>deg1;
	cout<<"Enter degree of polynomial 2: ";
	cin>>deg2;
	head1=insert(head,deg1); 
	head2=insert(start,deg2);
	cout<<"Polynomial 1: ";
	printlist(head1,deg1);
	cout<<endl<<"Polynomial 2: ";
	printlist(head2,deg2);
	if(deg1>deg2)
	{
		diff=deg1-deg2;
		sum(diff,deg1,head1,head2);
	}	
	else if(deg1<=deg2)
	{
		diff=deg2-deg1;
		sum(diff,deg2,head2,head1);
	}
	product(deg1,deg2,head1,head2);
	
}
