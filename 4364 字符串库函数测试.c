#include<stdio.h>
#include<string.h>

char input[55];
char instr[55];

char op[55];

void handler()
{
	if(strcmp(instr,"strlen")==0)
	{
		printf("%d\n",strlen(input));
	}
	else if(strcmp(instr,"strstr")==0)
	{
		scanf("%s",op);
		char *loc=strstr(input,op);
		if(loc==NULL)
		{
			printf("NULL\n");
		}
		else
		{
			printf("%d\n",loc-input);
		}
	}
	else if(strcmp(instr,"strcpy")==0)
	{
		scanf("%s",op);
		strcpy(input,op);
	}
	else if(strcmp(instr,"strcat")==0)
	{
		scanf("%s",op);
		strcat(input,op);
	}
}

int InstrCnt;

int main()
{
	scanf("%s",input);
	scanf("%d",&InstrCnt);
	while(InstrCnt--)
	{
		scanf("%s",instr);
		handler();
	}
	printf("%s\n",input);
}
