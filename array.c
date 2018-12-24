#include<stdio.h>
#include<stdlib.h>
void insert(int *A,int *n)
{
	int i,p,value;
	printf("\nEnter the value & position: ");
	scanf("%d%d",&value,&p);
	for(i=*n;i>=p;i--)
		A[i+1]=A[i];
	A[p]=value;
	*n=*n+1;
}
void traverse(int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}
void delete(int *A,int *n)
{
	int i,p;
	printf("\nEnter the position to be deleted: ");
	scanf("%d",&p);
	for(i=p+1;i<*n;i++)
		A[i-1]=A[i];
	*n=*n-1;
}
void reverse(int *A,int n)
{
	int i;
	for(i=n-1;i>=0;i--)
		printf("%d ",A[i]);
}
int main()
{
	int n=3,ch;
	int A[30]={1,2,3};
	while(1)
	{
		printf("1.Insert\n2.Traverse\n3.Deletion\n4.Reverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(A,&n);
					break;
			case 2: traverse(A,n);
					break;
            case 3: delete(A,&n);
					break;
            case 4: reverse(A,n);
					break;
            case 0: exit(0);
		}
	}
}
