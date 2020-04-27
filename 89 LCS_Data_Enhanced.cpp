#include<stdio.h>
#include<string.h>
#include<math.h>

#include<string>
#include<set>

using namespace std;

char A[110],B[110];
char tmp[110];
int n,m;
int dp[110][110];
int lasta[110][27];
int lastb[110][27];
int targetLen;
set<string> ans;

void init()
{
	memset(dp,0,sizeof(dp));
	memset(lasta,0,sizeof(lasta));
	memset(lastb,0,sizeof(lastb));
	memset(tmp,0,sizeof(tmp));
	ans.clear();
}

void buildDP()
{
	int i;
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= m; ++j)
		{
			if(A[i]==B[j])
			{
				dp[i][j]=dp[i][j]>(dp[i-1][j-1]+1)?dp[i][j]:(dp[i-1][j-1]+1);
			}
			else
			{
				dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}
	}
	targetLen=dp[n][m];
}

void buildLast()
{
	int i;
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 0; j < 26; ++j)
		{
			if(A[i] == 'A' + j)
			{
				lasta[i][j] = i;
			}
			else
			{
				lasta[i][j] = lasta[i - 1][j];
			}
		}
	}
	for(i = 1; i <= m; ++i)
	{
		int j;
		for(j = 0; j < 26; ++j)
		{
			if (B[i] == 'A' + j)
			{
				lastb[i][j] = i;
			}
			else
			{
				lastb[i][j] = lastb[i - 1][j];
			}
		}
	}
}

void dfs(int i, int j, int len)
{
	if(len <= 0)
	{
		ans.insert(string(tmp + 1));
		return;
	}
	if(i > 0 && j > 0)
	{
		int k;
		for(k = 0; k < 26; ++k)
		{
			int t1 = lasta[i][k];
			int t2 = lastb[j][k];
			if (dp[t1][t2] == len)
			{
				tmp[len] = 'A' + k;
				dfs(t1 - 1, t2 - 1, len - 1);
			}
		}
	}
}

void printAns()
{
	set<string>::iterator it;
	for(it=ans.begin();it!=ans.end();++it)
	{
		puts((*it).c_str());
	}
}

int main()
{
	while(~scanf("%s%s",A+1,B+1))
	{
		init();
		n=strlen(A+1);
		m=strlen(B+1);
		buildDP();
		buildLast();
		tmp[targetLen+1]='\0';
		dfs(n,m,targetLen);
		printAns();
	}
}
