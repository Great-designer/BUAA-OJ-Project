#include<stdio.h>

int a[110]; 

int main()
{
	int i;
	a[0]=1;
	for(i=1;i<105;i++)
	{
		a[i]=a[i-1]+a[i/2];
	}
    int x;
    scanf("%d",&x);
    x=x/2;
    printf("%d",a[x]);
}
