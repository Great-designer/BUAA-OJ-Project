#include<stdio.h>

int main()
{
	int DataNum=0;
	scanf("%d",&DataNum);
	for(int d=0; d<DataNum; d++)
	{
		char VariableName[10005]= {};
		scanf("%s",VariableName);
		int Index=0;
		if(VariableName[1]=='_') //匈牙利命名法
		{
			VariableName[1]='\n';
			VariableName[0]='\n';
			Index=2;
		}
		if(VariableName[Index]>='a'&&VariableName[Index]<='z') //驼峰命名法
		{
			VariableName[Index]+='A'-'a';
			Index++;
		}
		while (VariableName[Index])//下划线命名法或帕斯卡命名法
		{
			if(VariableName[Index]=='_')
			{
				VariableName[Index]='\n';
				if(VariableName[Index+1]>='a'&&VariableName[Index+1]<='z')
				{
					VariableName[Index+1]+='A'-'a';
				}
			}
			Index++;
		}
		Index=0;
		while (VariableName[Index])
		{
			if(VariableName[Index]!='\n')
			{
				putchar(VariableName[Index]);
			}
			Index++;
		}
		putchar('\n');
	}
	return 0;
}