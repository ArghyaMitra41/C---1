#include<stdio.h>
#include<stdlib.h>
void linearsearch(int a[],int n,int item)
{
	int loc=0,found=0,i=0;
	while(i<n)
	{
		if(item==a[i])
		{
			found=1;
			loc=i;
			printf("\nItem found at location %d",loc+1);
			break;
		}
		i=i+1;
	}
	if(found==0)
		printf("\nItem not found in the array");
}
void binarysearch(int a[],int lb,int ub,int item)
{
	int beg,end,mid,loc=0;
	beg=lb;
	end=ub;
	mid=(beg+end)/2;
	while(beg<=end && a[mid]!=item)
	{
		if(item<a[mid])
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	if(a[mid]==item)
	{
		loc=mid;
		printf("\nItem found at location: %d",loc+1);
	}
	else
		printf("\nItem not found in the array");
}
int interpolation(int a[],int low,int high,int item)
{
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)*((item-a[low])/(a[high]-a[low]));
		if(item==a[mid])
			return (mid+1);
		else
			return -1;
		if(item<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
}
int main()
{
        int i,n,ch,a[50],item;
	printf("\nEnter the number of element: ");
        scanf("%d",&n);
        printf("\nEnter the elements: ");
        for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the element to be found: ");
	scanf("%d",&item);
        while(1)
        {
                printf("\n1.Linear Search\n2.Binary Search\n3.Interpolation Search\n0.Exit\nEnter Your Choice...:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: linearsearch(a,n,item);
				break;
			case 2: binarysearch(a,0,n-1,item);
				break;
			case 3: if(interpolation(a,0,n-1,item)==-1)
					printf("\nItem not found in the array");
				else
					printf("\nItem found at location: %d",interpolation(a,0,n-1,item));
				break;
                        case 0: exit(0);
                }
        }
}
