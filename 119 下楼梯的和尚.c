#include<stdio.h>

int a[100010],n;

void buildDP()
{
    a[1]=1;
	a[2]=2;
	a[3]=4;
	int i;
    for(i=4;i<100010;++i)
	{
		a[i]=(a[i-1]+a[i-2]+a[i-3])%12211060;
	}
}

int main()
{
    buildDP();
    while(~scanf("%d",&n))
	{
		printf("%d\n",a[n]);
	}
}

