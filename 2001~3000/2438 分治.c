#include<stdio.h>
#include<stdlib.h>

long long frequency;

void merge(long long x[],long long tmp[],long long left,long long leftend,long long rightend)/*合并算法*/
{     
    long long i=left,j=leftend+1,q=left;
    while(i<=leftend&&j<=rightend)
    {
        if(x[i]<=x[j]) /*比较次数是指两组有序数据合并成一组时的比较次数*/
        {
        	tmp[q++]=x[i++];
		}
        else
        {
        	frequency+=leftend-i+1;
        	tmp[q++]=x[j++];
		}
    }
    while(i<=leftend)
    {
    	tmp[q++]=x[i++];
	}
    while(j<=rightend)
    {
    	tmp[q++]=x[j++];
	}
    for(i=left;i<=rightend;i++)
    {
    	x[i]=tmp[i];
	}
}

void mSort(long long k[],long long tmp[],long long left,long long right)/*调用merge时，要使用递归算法*/
{
    long long center;
    if(left<right)
	{
        center=(left+right)/2;
        mSort(k,tmp,left,center);
        mSort(k,tmp,center+1,right);
        merge(k,tmp,left,center,right);
    }
}

void mergeSort(long long k[],long long n)/*二路归并排序*/
{
    long long*tmp;
    tmp=(long long*)malloc(sizeof(long long)*n);
    if(tmp!=NULL) 
	{
        mSort(k,tmp,0,n-1);
        free(tmp);
    } 
//    else
//    {
//    	printf("No space for tmp array!!!\n");
//	}
}

long long k[100002];

int main()
{
	long long max;
	scanf("%lld",&max);
	long long i;
	for(i=0;i<max;i++)
	{
		scanf("%lld",&k[i]);
	}
	mergeSort(k,max);
	printf("%lld",frequency);
}
