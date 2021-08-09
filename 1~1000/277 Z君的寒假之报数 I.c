#include<stdio.h>

char exist[1010];
int n,k,loop,survive;
int start,prestart;

int main()
{
	scanf("%d%d",&n,&k);
	while(n!=0||k!=0)
	{
		if(!(n&1))
		{
			printf("no solution\n");
		} 
		else
		{
			survive=n;
			start=0;
			int i;
			for(i=0;i<n;++i)
			{
				exist[i]=1;
			}
			while(survive>1)
			{
				loop=k%survive;
				if(!loop)
				{
					loop+=survive;
				}
				if(loop==1)
				{
					prestart=(start+n-1)%n;
					while(!exist[prestart])
					{
						prestart=(prestart+n-1)%n;
					}
				}
				else
				{
					while(loop)
					{
						char mark=0;
						if(exist[start])
						{
							loop--;
							mark=1;
						}
						if(loop==1&&mark)
						{
							prestart=start;
						} 
						if(!loop)
						{
							break;
						} 
						start=(start+1)%n;
					}
				}
				exist[start]=exist[prestart]=0;
				while(!exist[start])
				{
					start=(start+1)%n;
				}
				survive-=2;
			}
			for(i=0;i<n;++i)
			{
				if(exist[i])
				{
					printf("%d\n",i+1);
					break;
				}
			}
		}
		scanf("%d%d",&n,&k);
	}
}
