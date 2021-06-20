#include<stdio.h>

int main()
{
    int a,b,c,t;
    while(scanf("%d%d%d",&a,&b,&c)==3)
	{
        if(a+b>c&&a+c>b&&b+c>a)
		{
            if(!(a-b&&a-c&&b-c))
			{
				printf("perfect\n");
			} 
            else
			{
                if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
                if(b>c)
				{
					t=b;
					b=c;
					c=t;
				}
                if(a*a+b*b==c*c)
				{
					printf("good\n");
				} 
                else
				{
					printf("just a triangle\n");
				} 
            }
        }
        else printf("wrong\n");
    }
}

