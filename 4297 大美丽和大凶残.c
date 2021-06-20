#include<stdio.h>
#include<math.h>

int mod(int m,int n)
{
	if(n<0)
	{
		n=-n;
	}
	int ans=m%n;
	while(ans<0)
	{
		ans+=n;
	}
	return ans;
}

int fish(int m,int n)
{
	if(m==1||n==1)
	{
		return 1;
	}
	if(m>0&&n==-1)
	{
		return 1;
	}
	if(m<0&&n==-1)
	{
		return -1;
	}
	if(m==-1&&mod(n,4)==1)
	{
		return 1;
	}
	if(m==-1&&mod(n,4)==3)
	{
		return -1;
	}
	if(abs(m)==abs(n))
	{
		return 0;
	}
	if(abs(n)>abs(m))
	{
		if((m>0||n>0)&&(mod(n,4)==1||mod(m,4)==1))
		{
			return fish(n,m);
		}
		else if(m<0&&n<0&&mod(n,4)==3&&mod(m,4)==3)
		{
			return fish(n,m);
		}
		else
		{
			return -fish(n,m);
		}
	}
	else
	{
		int temp=mod(m,n);
		if(mod(temp,2)==0)
		{
			if(temp>0)
			{
				temp-=abs(n);
			}
			else
			{
				temp+=abs(n);
			}
		}
		if(n<0&&((temp>0&&m<0)||(temp<0&&m>0)))
		{
			return -fish(temp,n);
		}
		else
		{
			return fish(temp,n);
		}
	}
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int ans=fish(m,n);
		if(ans==1)
		{
			printf("Great beauty!\n");
		}
		else if(ans==-1)
		{
			printf("Great ferocity!\n");
		}
		else
		{
			printf("Nonsense.\n");
		}
	}
}

