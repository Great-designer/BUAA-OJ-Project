#include<stdio.h>
#include<string.h>

char a[1028]; 

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		memset(a,0,sizeof(a));
		int i=0;
		while(n!=0)
		{
			a[i]=(char)(n%26)+'A'-1;
			n=n/26;
			i++;
		}
		for(i=strlen(a)-1;i>0;i--)
		{
			if(a[i-1]==('A'-1))
			{
				int t=i-1;
				while(a[t]==('A'-1))
				{
					a[t]='Z';
					if(a[t+2]=='\0'&&a[t+1]=='A')
					{
						a[t+1]='\0';
						continue;
					}
					a[t+1]-=1;
					t++;
				}
			}
		}
		for(i=strlen(a)-1;i>=0;i--)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
}

