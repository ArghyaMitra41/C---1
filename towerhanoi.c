#include<stdio.h>
int tower(int n,char beg,char aux,char end)
{
	if(n==1)
	{
		printf("%c->%c\n",beg,end);
		return;
	}
	tower(n-1,beg,end,aux);
	printf("%c->%c\n",beg,end);
	tower(n-1,aux,beg,end);
	return;
}
int main()
{
	int n;
	printf("\nEnter the number of disks: ");
	scanf("%d",&n);
	tower(n,'A','B','C');
}