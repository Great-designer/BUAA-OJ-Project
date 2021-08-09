#include<stdio.h>
#include<stdlib.h>

int a[10000000],ap[10000000];

int cmp(const void *p1,const void *p2)
{
    int *a=(int *)p1;
    int *b=(int *)p2;
    if(*a>*b)
    {
        return 1;
    }
    else if(*a<*b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
	int q,n,k;
	scanf("%d%d",&q,&k);
	int t,j,x=0;
	srand(1);
	for(t=0; t<100000; t++) //t次运算，使所有的数全部都被算出来
	{
		n=q;
		for(j=0; j<k; j++)
		{
			int i=rand()%2;//i要么是0，要么是1
			if (i==1)
			{
				n*=2;
			}
			else
			{
				n=n*3+1;
			}
			if(ap[n]==0) //有没有重复的
			{
				a[x++]=n;
				ap[n]=1;
			}
		}
	}
	qsort(a,x,4,cmp);//升序
	for(t=0; t<x; t++)
	{
		printf("%d ",a[t]);
	}
}
