#include<stdio.h>
#include<string.h>

int next[510];
char input[510];
int len;

int main()
{
	while(~scanf("%s",input))
	{
		memset(next,0,sizeof(next));
		int t=next[0]=-1;
		len=strlen(input);
		int j=0;
		while(j<len-1)
		{
			if(t<0||input[j]==input[t])
			{
				next[++j]=++t;
			}
			else
			{
				t=next[t];
			} 
		}
		int i; 
		for(i=0;i<len;++i)
		{
			printf("%d ",next[i]);
		}
		putchar('\n');
	}
}
