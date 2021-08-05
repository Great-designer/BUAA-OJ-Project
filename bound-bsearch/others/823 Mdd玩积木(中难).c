#include<stdio.h>

int a[1000010];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=0; i<n; ++i)
	{
		scanf("%d",&a[i]);
	}
	while(m--)
	{
		int k;
		scanf("%d",&k);
		int temp;
		if(!n)
		{
			temp=-1;
		}
		else if(n==1)
		{
			temp=(a[0]==k?0:-1);
		}
		else
		{
			int lo=0,hi=n-1,mi;
			int flag=0;
			while(lo<=hi)
			{
				mi=(lo+hi)>>1;
				if(k==a[mi])
				{
					temp=mi;
					flag=1;
					break;
				}
				if(a[0]<=a[mi])
				{
					if(a[0]<=k&&k<a[mi])
					{
						hi=mi-1;
					}
					else
					{
						lo=mi+1;
					}
				}
				else
				{
					if(a[mi]<k&&k<=a[n-1])
					{
						lo=mi+1;
					}
					else
					{
						hi=mi-1;
					}
				}
			}
			if(flag==0)
			{
				temp=-1;
			}
		}
		puts(temp>=0?"Yes":"No");
	}
}
