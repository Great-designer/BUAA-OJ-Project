#include<stdio.h>
 
int gcd(int x,int y)
{
	if(y==0)
    {
       return x;
    }
	else
    {
       return gcd(y,x%y);
    }
}

int main()
{
	int n,m,k;
	while(~scanf("%d%d",&n,&m))
    {
       k=gcd(n,m);
       if(k==1)
       {
           printf("jhljxshidadoubi\n");
       }
       else
       {
           printf("shuishuowoshidadoubi\n");
       }
    }
}

