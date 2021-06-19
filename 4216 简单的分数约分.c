#include<stdio.h>

int main()
{
	int m=0,n=0;
	int M=0,N=0;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		int GCD=0;
		int Max=0,Min=0;
		if(n<0)
		{
			n*=-1;
			m*=-1;
		}
		if (m<0)M=-m;
		else M=m;
		if (N<0)N=-n;
		else N=n;
		if(m%n==0)
		{
			printf("%d\n",m/n);
		}
		else
		{
			if(M/N==0)
			{
				if(M>=N)
				{
					Max=M;
					Min=N;
				}
				else
				{
					Max=N;
					Min=M;
				}
				while(Min)
				{
					int Temp=Max%Min;
					Max=Min;
					Min=Temp;
				}
				GCD=Max;
				printf("%d/%d\n",m/GCD,n/GCD);
			}
			else
			{
				int Integer=m/n;
				m-=n*Integer;
				if(M>=N)
				{
					Max=M;
					Min=N;
				}
				else
				{
					Max=N;
					Min=M;
				}
				while(Min)
				{
					int Temp=Max%Min;
					Max=Min;
					Min=Temp;
				}
				GCD=Max;
				printf("%d%+d/%d\n",Integer,m/GCD,n/GCD);
			}
		}
	}
	return 0;
}