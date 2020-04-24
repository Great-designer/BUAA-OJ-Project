#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partion(int A[],int low,int high)
{
    int x=A[high];
    int i=low-1;
	int j;
    for(j=low;j<high;j++)
    {
        if(A[j]<=x)
        {
        	++i;
        	int temp=A[i];
        	A[i]=A[j];
        	A[j]=temp;
		}
    }
    ++i;
    int temp=A[i];
    A[i]=A[high];
    A[high]=temp;
    return i;
}

int randomPartion(int A[],int low,int high)
{
    int i=rand()%(high-low+1)+low;
    int temp=A[i];
    A[i]=A[high];
    A[high]=temp;
    return partion(A,low,high);
}

int randomSelect(int A[],int low,int high,int i)
{
    if(low==high)
    {
    	return A[low];
	}
    int temp=randomPartion(A,low,high);
    int order=temp-low+1;
    if(i==order)
    {
    	return A[temp];
	}
    else if(i<order)
    {
    	return randomSelect(A,low,temp-1,i);
	}
    else
    {
    	return randomSelect(A,temp+1,high,i-order);
	}
}

int A[1000001];

int main()
{
    srand(time(NULL));
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        getchar();
        int i;
        for(i=0;i<n;i++)
        {
        	scanf("%d",&A[i]);
		}
        if(k>0&&k<=n)
        {
        	printf("%d\n",randomSelect(A,0,n-1,n-k+1));
		}
    }
}

