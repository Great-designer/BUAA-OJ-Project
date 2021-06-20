#include<stdio.h>

int indexS[80010];
int top;
int a[80010];
int n;
long long result;

int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	a[n++]=2147483647;
	result=0;
	for(i=0;i<n;++i)
	{
		if(top==0||(top!=0&&a[indexS[top-1]]>a[i]))
		{
			indexS[top]=i;
			top++;
		}
		else
		{
			while(top!=0&&a[indexS[top-1]]<=a[i])
			{
				int to=indexS[top-1];
				top--;
				result+=((long long)i-(long long)to-(long long)1);
			}
			indexS[top]=i;
			top++;
		}
	}
	printf("%lld",result);
}
