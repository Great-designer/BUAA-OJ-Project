#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==0)
		{
			putchar('0');
			putchar('\n');
			continue;
		}
		double len=floor((log((double)a)/log(3.0))+1e-10);
		int loc=(int)pow(3,len);
		int i;
		for(i=len;i>=0;i--)
		{
			char t=a/loc%3+'0';
			putchar(t);
			loc/=3;
		}
		putchar('\n');
	}
}