#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//s1 s2存放读入的两段程序 去掉空白字符后的总字符串
//stemp暂存某一行
char s1[1000],s2[1000],stemp[105];
int s1pos=0,s2pos=0;
int n1,n2,m;

int do_str(char *s,int spos)
{
	char* pos=NULL;
	char* t=stemp;
	gets(stemp);
	pos=strstr(stemp,"//");//寻找注释字符的位置，并在该位置标结束符号。相当于截断字符串 去掉了注释
	if(pos!=NULL)
	{
		*pos='\0';
	}
	//去掉空白字符 将非空白字符读入 空白字符跳过
	while(*t!='\0')
	{
		if(*t!=' '&&*t!='\n'&&*t!='\r'&&*t!='\t')
		{
			s[spos]=*t;
			spos++;
		}
		t++;
	}
	return spos;
}


int main()
{
	int i,sumk=0;
	char *t;
	scanf("%d%d%d",&n1,&n2,&m);
	while(getchar()!='\n');//去掉行尾空白字符 很重要
	for(i=0; i<n1; i++)
	{
		s1pos=do_str(s1,s1pos);
	}
	s1[s1pos]='\0';
	for(i=0; i<n2; i++)
	{
		s2pos=do_str(s2,s2pos);
	}
	s2[s2pos]='\0';
	for(i=0; i<=s1pos-m; i++)
	{
		strncpy(stemp,s1+i,m);//复制指定长度字符串
		stemp[m]='\0';//补\0，否则后续程序找不到字符串结尾
		t=strstr(s2,stemp);//按长度匹配
		if(t!=NULL) //若匹配成功则计数
		{
			sumk++;
		}
	}
	printf("%d",sumk);
	return 0;
}