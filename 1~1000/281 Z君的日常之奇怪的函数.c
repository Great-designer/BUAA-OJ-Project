#include<stdio.h>
#include<string.h>

int n,q;
int a[100010];
int le[100010];
int l,r;
int tmp1,tmp2;

long long res;
int s[100010];
int top;

void getAns(int l,int r)
{
	top=0;
	memset(le,0,sizeof(le));
	res=0;
	r--;
	top=0;
	int i; 
	for(i=l;i<=r;++i)
	{
		while(top!=0&&a[s[top-1]]<a[i])
		{
			res+=1ll*(i-s[top-1])*(s[top-1]-le[s[top-1]])*a[s[top-1]];
			top--;
		}
		le[i]=(top==0?(l-1):(s[top-1]));
		s[top]=i;
		top++;
	}
	r++;
	while(top!=0)
	{
		res+=1ll*(r-s[top-1])*(s[top-1]-le[s[top-1]])*a[s[top-1]];
		top--;
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	scanf("%d",&tmp1);
	int i;
	for(i=1;i<n;++i)
	{
		scanf("%d",&tmp2);
		a[i]=(tmp2>tmp1)?(tmp2-tmp1):(tmp1-tmp2);
		tmp1=tmp2;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		getAns(l,r);
		printf("%lld",res);
		putchar('\n');
	}
}
