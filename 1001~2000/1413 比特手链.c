#include<stdio.h>
#include<string.h>

char S1[1000009],S2[1000009];

int main() 
{
	int T;
	scanf("%d",&T);
	while (T--) 
	{
		scanf("%s%s",S1,S2);
		int dif1=0;
		int dif2=0;
		int b0=0;
		int i;
		int str=strlen(S1);
		for(i=0;i<str;i++)
		{
			if(S1[i]=='0')
			{
				b0++;
			}
			if(S2[i]=='1'&&S1[i]=='0')
			{
				dif1++;
			}	
			else if(S2[i]=='0'&&S1[i]=='1')
			{
				dif2++;
			}
		}
		if(b0==str||b0==0)
		{
			printf("-1\n");
		}
		else
		{
			int max=(dif1>dif2?dif1:dif2);
			printf("%d\n",max);
		}
	}
	return 0;
}
