#include<stdio.h>

int a[1000010];
int n;
int ans1,ans2,ans;
int pos;

int main()
{
	while(~scanf("%d",&n))
	{
		ans1=ans2=ans=pos=0;
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		for(i=0;i<=31;++i)
		{
			if(ans&(1<<i))
			{
				pos=i;
				break;
			}
		}
		pos=1<<pos;
		for(i=1;i<=n;++i)
		{
			if(a[i]&pos)
			{
				ans1^=a[i];
			}
			else
			{
				ans2^=a[i];
			}
		}
		if(ans1>ans2)
		{
			int tmp=ans1;
			ans1=ans2;
			ans2=tmp;
		}
		printf("%d %d\n",ans1,ans2);
	}
}
