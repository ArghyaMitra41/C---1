#include<stdio.h>
#include<stdlib.h>
void bubble(int a[],int n)
{
	int swap=1,i=0,temp;
	while(swap==1 && i<n)
	{
		swap=0;
		int j=0;
		while(j<(n-i-1))
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
			j=j+1;
		}
		i=i+1;
	}
}
void insertion(int a[],int n)
{
	int j,i,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && temp<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=temp;
	}
}
void selection(int a[],int n)
{
	int j,k,loc,temp;
	for(k=0;k<n-1;k++)
	{
		loc=k;
		for(j=k+1;j<n;j++)
		{
			if(a[j]<a[loc])
				loc=j;
		}
		if(loc!=k)
		{
			temp=a[k];
			a[k]=a[loc];
			a[loc]=temp;
		}
	}
}
void merge(int a[],int ls,int rs,int re)
{
	int k=0,i=ls,j=rs,temp[50];
	int le=rs-1;
	
	while(i<=le && j<=re)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i];
			i++;
		}
		else
		{
			temp[k++]=a[j];
			j++;
		}
	}
	while(i<=le)
	{
		temp[k++]=a[i];
		i++;
	}
	while(j<=re)
	{
		temp[k++]=a[j];
		j++;
	}
	for(i=1;i<=k;i++)
		a[ls-1+i]=temp[i-1];
}
void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{	
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q+1,r);
	}
}
void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int partition(int a[],int p,int r)
{
	int x,i,j,temp;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return(i+1);
}
int main()
{
        int i,n,ch,a[50];
	printf("\nEnter the number of element: ");
        scanf("%d",&n);
        printf("\nEnter the elements: ");
        for(i=0;i<n;i++)
		scanf("%d",&a[i]);
        while(1)
        {
                printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Merge Sort\n5.Quick Sort\n6.Traverse\n0.Exit\nEnter Your Choice...:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: bubble(a,n);
                                break;
                        case 2: insertion(a,n);
                                break;
                        case 3: selection(a,n);
                                break;
			case 4: mergesort(a,0,n-1);
                                break;
			case 5: quicksort(a,0,n-1);
				break;
			case 6: for(i=0;i<n;i++)
					printf("%d ",a[i]);
				break;
                        case 0: exit(0);
                }
        }
}
