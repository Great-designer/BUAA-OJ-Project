#include <stdio.h>
int a[10];
int main()
{
	int m,n;
	int i;
	scanf("%d %d",&m,&n);
	if(m==0)
		a[0]++;
	for(; m<=n; m++)
		for(i=m; i; i/=10)
			a[i%10]++;
	for(i=0; i<=9; i++)
		printf("%d ",a[i]);
	return 0;
}