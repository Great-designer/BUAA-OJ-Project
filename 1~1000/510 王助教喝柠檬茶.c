#include<stdio.h>
#include<stdlib.h>

int n,v,m;
int a[1010];
int lessrequest[1010];
int maxrequest[1010];
int loss;

int compare(const void *p1,const void *p2)
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
	scanf("%d%d%d",&n,&v,&m);
	int i;
	for(i=1;i<=n;++i)
	{ 
		scanf("%d",a+i);
	}
	qsort(a+1,n,sizeof(int),compare);
	for(i=1;i<=n;++i)
	{
		lessrequest[a[i]]=i*v;
	} 
	if(m==0)
	{
		printf("0 %d\n",n*v);
		return 0;
	}
	int cur=1+lessrequest[0],Index=1;
	while(cur<=n*v)
	{
		if(!lessrequest[Index])
		{
			lessrequest[Index]=cur; 
		}
		else
		{
			if(lessrequest[Index]>=cur)
			{
				cur=lessrequest[Index];
			}
			else
			{
				lessrequest[Index]=cur+1;
			}
		}
		cur++;
		Index++;
	}
	int lim=Index-1;
	if(lim==0)
	{
		printf("0 %d\n",n*v);
		return 0;
	}
	loss+=lessrequest[0];
	for(i=1;i<=lim;++i)
	{
		maxrequest[i]=m*i+loss;
	}
	for(i=1;i<=lim;++i)
	{
		if(lessrequest[i]>maxrequest[i])
		{
			int tmp=lessrequest[i]-maxrequest[i];
			loss+=tmp;
			int j;
			for(j=i+1;j<=lim;++j)
			{
				maxrequest[j]+=tmp;
			}
		}
	}
	printf("%d %d\n",lim,loss);
}
