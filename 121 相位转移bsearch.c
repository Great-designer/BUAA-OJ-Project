#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

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

int lo,hi,mi;
int x,m,t;
int a[100010];
int s[100010];
int pre,now;

int lower(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a<=*(b-1))
	{
		return -1;
	}
	else if((*a>*(b-1))&&*a>*b)
	{
		return 1;
	}
	else if((*a>*(b-1))&&*a<=*b)
	{
		return 0;
	}
}

int main()
{
	while(~scanf("%d%d%d",&x,&m,&t))
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		pre=0;
		lo=hi=x;
		int i;
		for(i=1; i<=m; ++i)
		{
			scanf("%d",&s[i]);
		}
		s[++m]=x;
		qsort(s+1,m,sizeof(int),compare);
		for(i=1; i<=m; ++i)
		{
			a[i]=s[i]-s[i-1];
			if(a[i]<lo)
			{
				lo=a[i];
			}
		}
		if(t==m-1)
		{
			printf("%d\n",x);
			continue;
		}
		else if(t==0)
		{
			printf("%d\n",lo);
			continue;
		}
		s[0]=INT_MIN;
		while(lo<=hi)
		{
			mi=(lo+hi)>>1;
			int needK=0;
			int cur=1;
			while(cur<=m)
			{
				if(cur==m)
				{
					if(a[cur]<mi)
					{
						needK+=1;
					}
					break;
				}
				else if(a[cur]<mi)
				{
					int key=s[cur]+mi-a[cur];
					int *pos=bsearch(&key,s+1,m,sizeof(int),lower);
					if(pos==NULL)
					{
						pos=s+1+m;
					}
					needK+=pos-s-cur;
					cur=pos-s+1;
				}
				else
				{
					cur++;
				}
			}
			if(needK>t)
			{
				hi=mi-1;
			}
			else
			{
				lo=mi+1;
			}
		}
		printf("%d\n",lo-1);
	}
}
