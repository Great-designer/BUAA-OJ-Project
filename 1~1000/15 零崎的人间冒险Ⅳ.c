#include<stdio.h>
#include<string.h>

int n;

int Partition(int A[],int p,int r)
{
    int i=p-1;
    int key=A[r];
    int j;
    for(j=p;j<=r-1;j++)
    {
    	if(A[j]<key)
    	{
    		++i;
    		int temp=A[i];
    		A[i]=A[j];
    		A[j]=temp;
		}
	}
	++i;
	int temp=A[i];
    A[i]=A[r];
    A[r]=temp;
    return i;
}

void QuickSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main()
{
    int A[100010];
    while(~scanf("%d",&n))
    {
        memset(A,0,sizeof(A));
        int i;
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&A[i]);
		}
        QuickSort(A,1,n);
        for(i=1;i<=n;i++)
        {
        	printf("%d ",A[i]);
		}
        printf("\n");
    }
}
