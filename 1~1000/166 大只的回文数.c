#include<stdio.h>

int f[12]={0,9,18,108,198,1098,1998,10998,19998,109998,199998,1099998};

int find(int x)
{
	if(x<10)
	{
		return x;
	}
	int l=0;
	int remain=x;
	while(remain)
	{
		l++;
		remain/=10;
	}
	int t=1;
	int ans=f[l-1];
	int k;
	for(k=1;k<=(l>>1);++k)
	{
		t*=10;
	}
	int na=0,a=x/t;
	if(l&1)
	{
		t*=10;
	}
	int b=x%t;
	t/=10;
	ans+=a-t;
	while(a)
	{
		na=na*10+a%10;
		a/=10;
	}
	if(b>=na)
	{
		ans++;
	}
	return ans;
}

int m,n;

int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		if(m>n)
		{
			int t=m;
			m=n;
			n=t;
		}
		printf("%d\n",find(n)-find(m-1));
	}
}
