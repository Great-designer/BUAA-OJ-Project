#include<stdio.h>

int main()
{
    int a,b,t;
    while(scanf("%d%d",&a,&b)==2)
	{
        if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
        printf("%d %d\n",b,(a-b)>>1);
    }
}

