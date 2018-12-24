#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *create(struct node *head,int n)
{
	struct node *ptr,*temp;
	int i,value;
	if(head!=NULL)
	{
		printf("\nList already exists");
		return(head);
	}
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the value: ");
		scanf("%d",&value);
		ptr=(struct node *)malloc(sizeof(ptr));
		ptr->info=value;
		ptr->next=NULL;
		if(head==NULL)
			head=ptr;
		else
			temp->next=ptr;
		temp=ptr;
	}
	return(head);
}
void traverse(struct node *head)
{
	struct node *loc;
	loc=head;
	while(loc!=NULL)
	{
		printf("%d ",loc->info);
		loc=loc->next;
	}
}
struct node *insbeg(struct node *head,int n)
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\nList doesn't exist");
		return(head);
	}
	ptr=(struct node *)malloc(sizeof(ptr));
	ptr->info=n;
	ptr->next=head;
	head=ptr;
	return(head);
}
struct node *insend(struct node *head,int n)
{
	struct node *ptr,*temp;
		if(head==NULL)
        {
                printf("\nList doesn't exist");
                return(head);
        }
        ptr=(struct node *)malloc(sizeof(struct node));
        temp=head;
        while(temp->next!=NULL)
                temp=temp->next;
		ptr->info=n;
        ptr->next=NULL;
        temp->next=ptr;
        return(head);
}
struct node *delbeg(struct node *head)
{
    struct node *ptr;
        if(head==NULL)
        {
                printf("\nList doesn't exist");
                return(head);
        }
	ptr=head;
	head=head->next;
	free(ptr);
	return(head);
}
struct node *delend(struct node *head)
{       
    struct node *ptr,*preptr;
    if(head==NULL)
    {
        printf("\nList doesn't exist");
        return(head);
    }
    ptr=head;
    while(ptr->next!=NULL)
	{
		preptr=ptr;
        ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return(head);
}
void count(struct node *head)
{
	struct node *loc;
	int c=0;
	loc=head;
	while(loc!=NULL)
	{
		c+=1;
		loc=loc->next;
	}
	printf("\nNumber of Elements = %d",c);
}
struct node *reverse(struct node *head,int n)
{
	struct node *loc,*locp,*locn;
	if(head==NULL)
	{
		printf("\nList does not exists");
		return(head);
	}
	loc=head;
	locp=NULL;
	locn=loc->next;
	loc->next=locp;
	while(locn!=NULL)
	{
		locp=loc;
		loc=locn;
		locn=loc->next;
		loc->next=locp;
	}
	head=loc;
	return(head);
}
int main()
{
	int i,n,ch;
	struct node *head=NULL;
	while(1)
	{
		printf("\n1.Create\n2.Insert Beginning\n3.Insert End\n4.Delete Beginning\n5.Delete End\n6.Traverse\n7.Count\n8.Reverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the number of nodes: ");
					scanf("%d",&n);
					head=create(head,n);
					break;
			case 2: printf("\nEnter the value: ");
					scanf("%d",&n);
                    head=insbeg(head,n);
                    break;
            case 3: printf("\nEnter the value: ");
                    scanf("%d",&n);
                    insend(head,n);
                    break;
            case 4: head=delbeg(head);
                    break;
            case 5: head=delend(head);
                    break;
            case 6: traverse(head);
                    break;
			case 7: count(head);
					break;
			case 8: head=reverse(head,n);
					break;
            case 0: exit(0);
		}
	}
}
