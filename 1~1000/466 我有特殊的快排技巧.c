#include<stdio.h>
#include<string.h>

void QUICKSORT(int A[],int p,int r,int m)
{
    if(p<r)
    {
        int q=PARTITION(A,p,r);
        if(m==q)
        {
            return;
        }
        else if(m<q)
        {
            QUICKSORT(A,p,q-1,m);
        }
        else
        {
            QUICKSORT(A,q+1,r,m);
        }
    }
}

int PARTITION(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    int j; 
    for(j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

int A[100000];

int main()
{
    unsigned int length;
    while(~scanf("%d",&length))
    {
    	int i;
        for(i=0;i<length;i++)
        {
            while(scanf("%d",&A[i])==EOF);
        }
        QUICKSORT(A,0,length-1,(length-1)/2);
        printf("%d\n",A[(length-1)/2]);
    }
    return 0;
}


