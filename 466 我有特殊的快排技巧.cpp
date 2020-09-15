#include<stdio.h>
#include<algorithm>

using namespace std;

int n,pos;
int num[100007];

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]); 
		}
		pos=(n+1)/2;
		nth_element(num,num+pos-1,num+n);
		printf("%d\n",num[pos-1]);
	}
}

