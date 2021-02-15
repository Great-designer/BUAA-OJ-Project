#include<stdio.h>
#include<algorithm>

using namespace std;

int a[100010];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		int u=upper_bound(a,a+n,x)-a;
		int l=lower_bound(a,a+n,x)-a;
		if(u!=l)
		{
			printf("Yes %d %d\n",l+1,u-l);
		}
		else
		{
			printf("No\n");
		}
	}
}
