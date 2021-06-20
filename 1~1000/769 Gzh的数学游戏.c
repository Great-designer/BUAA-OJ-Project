#include<stdio.h>
#include<math.h>

unsigned long long ans;
int n,m;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(m==1)
		{
			ans=1;
		}
		else if(m==2||m==3||m==5||m==7||m==11)
		{
			ans=pow(m,n)-1;
		}
		else if(m==4||m==9)
		{
			ans=pow(m,n)-pow((int)sqrt(m),n);
		}
		else if(m==6||m==10)
		{
			ans=pow(m,n)-pow(2,n)-pow(m>>1,n)+1;
		}
		else if(m==8)
		{
			ans=pow(m,n)-pow(4,n);
		}
		printf("%llu\n",ans);
	}
}
