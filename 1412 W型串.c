#include<stdio.h>
#include<string.h>

char s[1009];

char judge(int left,int right)
{
	if(left==right)
	{
		return 1;
	}
	if(s[left]!='('||s[right-1]!=')')
	{
		return 0;
	}
	if(s[left]=='('&&s[left+1]==')'&&(right-left)==2)
	{
		return 1;
	}
	int topS=0;
	int i;
	for(i=left;i<right;i++)
	{
		if(s[i]=='(')
		{
			topS++;
		}
		else
		{
			topS--;
		}
		if(topS==0)
		{
			if(i==right-1)
			{
				i++;
			}
			break;
		}
	}
	if(topS!=0)
	{
		return 0;
	}
 	if(i==right)
	{
		return judge(left+1,right-1);
	}
	else
	{
		return (judge(left+1,i)&&judge(i+2,right-1));
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		if(judge(0,strlen(s)))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
