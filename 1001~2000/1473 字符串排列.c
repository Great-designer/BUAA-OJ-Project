#include<stdio.h>
#include<string.h>

int cnt[2][300];
char s[2][1010];

int main()
{
	while(~scanf("%s%s",s[0],s[1]))
	{
		memset(cnt,0,sizeof(cnt));
		int kd; 
		for(kd=0;kd<2;kd++)
		{
			int i;
			for(i=0;i<strlen(s[kd]);i++)
			{
				cnt[kd][s[kd][i]]++;
			}
		}
		char flag=1;
		int i;
		for(i=0;i<=255;i++)
		{
			flag&=(cnt[0][i]==cnt[1][i]);
		}
		if(flag)
		{
			printf("TAK\n");
		}
		else
		{
			printf("NIE\n");
		}
	}
}
