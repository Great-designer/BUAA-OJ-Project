#include<stdio.h>
#include<string.h>

struct name
{
	char cal[25];
	int times;
};

struct name templ[25];

char ret[25];
char com[25];

int main()
{
	memset(templ,0,sizeof(templ));
	int top=0;
	while(~scanf("%s",com))
	{
		int flag=0;
		int i;
		for(i=0;i<top;i++)
		{
			if(strcmp(com,templ[i].cal)==0)
			{
				templ[i].times++;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			strcpy(templ[top].cal,com);
			templ[top].times++;
			top++;
		}
	}
	int ans=0;
	int i;
	for(i=0;i<top;i++)
	{
		if(templ[i].times>ans)
		{
			strcpy(ret,templ[i].cal);
			ans=templ[i].times;
		}
	}
	printf("%s",ret);
}