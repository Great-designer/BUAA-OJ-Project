#include<stdio.h>

int Solve(int k1)
{
	int k2=k1^(k1<<1)&255;
	int k4=k2^(k2<<2)&255;
	int k8=k4^(k4<<4)&255;
	return k8;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a;
		scanf("%d",&a);
		int b=Solve(a);
		printf("%d ",b);
	}
}