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
		if(f())//���˴����жϣ�������Ϊ{pair,int}ʱ��f���������1����WA
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
	for(i=0;i<num;i++)
	{
		memset(res,0,sizeof(char));//ÿ��ѭ�������ԭ�ȵ�res
		scanf("%d",&k);
		int j;
		for(j=0;j<k;j++)
		{
			scanf("%s",s[j]);
		}
		cur=0;
		if(strcmp(s[0],"int")!=0)//�����һ��������int��ֱ�����Error 
		{	
			t=f();
		} 
		if(cur!=k||t==0)//cur!=k�ж��Ƿ�����ʣ��
		{ 
			printf("Error occurred\n");//t==0���жϺ����쳣���������
		} 
		else
		{
			printf("%s\n",res);
		}
	}	
}
