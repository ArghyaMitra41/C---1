#include<stdio.h>
int fiborec(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return(fiborec(n-1)+fiborec(n-2));
}
int main()
{
	int n,i;
	printf("\nEnter the limit: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		printf("\t%d",fiborec(i));
}