#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>

using namespace std;

int h[100001];

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

char cover(int d,int m,int n)
{
	int e=1;
	int cnt=0;
	while(e<=n)
	{
		cnt++;
		if(cnt>m)
		{ 
			return 0;
		}
		e=upper_bound(h+1,h+n+1,h[e]+d)-h;
	}
	return 1;
}

int main()
{
	int m,n;	
	scanf("%d%d",&m,&n);	
	int i; 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);	
	}
	qsort(h+1,n,sizeof(int),compare);	
	int l=1;
	int r=h[n]-h[1]+1;	
	while(l<r)
	{	
		int mid=(l+r)>>1;		
		if(cover(mid,m,n))
		{
			r=mid;	
		}	
		else 
		{
			l=mid+1; 
		}	
	}	
	printf("%.1lf",(double)l/2.0);
	return 0;
}

