#include<stdio.h>
#include<string.h>

char res[10000],s[1005][10];

int cur,num,t,k;

int f()
{
	if(strcmp(s[cur],"pair")==0)
	{
		cur++;
		strcat(res,"pair<");
		f();
		strcat(res,",");
		if(f())//若此处无判断，当输入为{pair,int}时，f会继续返回1导致WA
		{
			strcat(res,">");
			return 1;
		}
	}
	if(strcmp(s[cur],"int")==0)
	{
		cur++;
		strcat(res,"int");
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&num);
	int i;
	for(i=0; i<num; i++)
	{
		memset(res,0,sizeof(char));//每个循环后清空原先的res
		scanf("%d",&k);
		int j;
		for(j=0; j<k; j++)
		{
			scanf("%s",s[j]);
		}
		cur=0;
		if(strcmp(s[0],"int")!=0)//如果第一个单词是int则直接输出Error
		{
			t=f();
		}
		if(cur!=k||t==0)//cur!=k判断是否有项剩余
		{
			printf("Error occurred\n");//t==0是判断函数异常结束的情况
		}
		else
		{
			printf("%s\n",res);
		}
	}
}
