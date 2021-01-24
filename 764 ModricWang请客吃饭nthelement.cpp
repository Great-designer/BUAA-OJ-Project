#include<stdio.h>
#include<algorithm>

using namespace std;

int a[1000010];
int n,k;

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		nth_element(a,a+k,a+n);
		printf("%d\n",a[k-1]);
	}
}
