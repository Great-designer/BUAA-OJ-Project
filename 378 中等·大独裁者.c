#include<stdio.h>

char alive[25];
int n,k,m;
int realk,realm;
int cnt;
int l,r;
int cur;

int main()
{
	while((~scanf("%d%d%d",&n,&k,&m))&&(n||k||m))
	{
		int i;
		for(i=0;i<n;++i)
		{
			alive[i]=1;
		}
		l=0;
		r=n-1;
		cur=n;
		while(cur)
		{
			realk=k%cur;
			realm=m%cur;
			if(!realk)
			{
				realk+=cur;
			}
			if(!realm)
			{
				realm+=cur;
			}
			int tmp=1;
			while(tmp<realk)
			{
				l=(l+1)%n;
				if(alive[l])
				{
					tmp++;
				}
			}
			tmp=1;
			while(tmp<realm)
			{
				r=(r+n-1)%n;
				if(alive[r])
				{
					tmp++;
				}
			}
			if(l==r)
			{
				printf("%3d",l+1);
				alive[l]=0;
				cur--;
				if(cur)
				{
					printf(",");
					while(!alive[l])
					{
						l=(l+1)%n;
					}
					while(!alive[r])
					{
						r=(r+n-1)%n;
					}
				}
			}
			else
			{
				printf("%3d%3d",l+1,r+1);
				alive[l]=alive[r]=0;
				cur-=2;
				if(cur)
				{
					printf(",");
					while(!alive[l])
					{
						l=(l+1)%n;
					}
					while(!alive[r])
					{
						r=(r+n-1)%n;
					}
				}
			}
		}
		puts("");
	}
}
