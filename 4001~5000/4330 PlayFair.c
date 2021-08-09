#include<stdio.h>
#include<string.h>
#include<ctype.h>

char c1, c2;
char mima[5][5];

int findX(char p)//在密码表中找到该字母的X坐标
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (mima[i][j] == p) return i;
		}
	}
}

int findY(char p)//在密码表中找到该字母的Y坐标
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (mima[i][j] == p) return j;
		}
	}
}

void jiami(char p1, char p2)
{
	if (findX(p1) == findX(p2))//p1 p2在同一行的情况
	{
		if (findY(p1) == 4) printf("%c", mima[findX(p1)][0]);//针对最后一行单独讨论
		else printf("%c", mima[findX(p1)][findY(p1) + 1]);
		if (findY(p2) == 4) printf("%c", mima[findX(p2)][0]);//针对最后一行单独讨论
		else printf("%c", mima[findX(p2)][findY(p2) + 1]);
	}
	else if (findY(p1) == findY(p2))  //p1 p2在同一列的情况
	{
		if (findX(p1) == 4) printf("%c", mima[0][findY(p1)]);//针对最右一列单独讨论
		else printf("%c", mima[findX(p1) + 1][findY(p1)]);
		if (findX(p2) == 4) printf("%c", mima[0][findY(p2)]);//针对最右一列单独讨论
		else printf("%c", mima[findX(p2) + 1][findY(p2)]);
	}
	else printf("%c%c", mima[findX(p2)][findY(p1)], mima[findX(p1)][findY(p2)]);
}

int main()
{
	char s[20], in[300];
	int zimu[25] = {0};
	int i, j = 0, k = 0;
	scanf("%s", s);
	scanf("%s", in);
	for (i = 0; i < strlen(s); i++)//将密钥编入密码表
	{
		if (!zimu[tolower(s[i]) - 'a'])//确认密钥中的字母没有出现过
		{
			zimu[tolower(s[i]) - 'a']++;
			mima[j][k] = tolower(s[i]);
			j++;
			if (j == 5)
			{
				j = 0;
				k++;
			}
		}
	}
	for (i = 0; i < 25; i++)//将密钥中未出现的字母编入密码表
	{
		if (!zimu[i])
		{
			mima[j][k] = i + 'a';
			j++;
			if (j == 5)
			{
				j = 0;
				k++;
			}
		}
	}
	for (i = 0; i < strlen(in);)//对明文进行加密
	{
		if (i == strlen(in) - 1)//明文仅剩一个字母，需要补字母x
		{
			jiami(tolower(in[i]), 'x');
			break;
		}
		else if (tolower(in[i]) == tolower(in[i + 1]))  //明文字母相同，需要插入字母x
		{
			jiami(tolower(in[i]), 'x');
			i++;
		}
		else   //一般情况
		{
			jiami(tolower(in[i]), tolower(in[i + 1]));
			i += 2;
		}
	}
	return 0;
}