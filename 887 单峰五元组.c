#include<stdio.h>

int a[10];

int main()
{
	scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	if(a[2]>a[1]&&a[1]>a[0]&&a[2]>a[3]&&a[3]>a[4])
	{
		printf("Yes");
		return 0;
	}
	printf("No");
}
