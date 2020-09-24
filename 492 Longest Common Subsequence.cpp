#include<stdio.h>
#include<iostream>
#include<string.h>
#include<set>
#include<algorithm>

using namespace std;

int len1,len2,len;
int dp[107][107];

set<string> ans;

char s1[107]=" ",s2[107]=" ";

void LCS(char A[],char B[])
{
	memset(dp,0,sizeof(dp));
	len1=(int)strlen(A),len2=(int)strlen(B);
	int i;
	for(i=1;i<=len1;i++)
	{
	    int j;
		for(j=1;j<=len2;j++)
		{
			dp[i][j]=(dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1]);
			if(A[i]==B[j])
			{
				dp[i][j]=dp[i][j]>(dp[i-1][j-1]+1)?dp[i][j]:(dp[i-1][j-1]+1);
			}
		}
	}
	len=dp[len1][len2];
}

void go(int i,int j,string s)
{
	if(i<=0||j<=0)
	{
		return;
	}
	if(s1[i]==s2[j])
	{
		s.push_back(s1[i]);
		if(s.length()==len)
		{
			reverse(s.begin(),s.end()),ans.insert(s);
		}
		else
		{
			go(i-1,j-1,s);
		}
	}
	else
	{
		if(dp[i-1][j]>=dp[i][j-1])
		{
			go(i-1,j,s);
		}
		if(dp[i][j-1]>=dp[i-1][j])
		{
			go(i,j-1,s);
		}
	}
}

int main()
{
	while(~scanf("%s%s",s1+1,s2+1))
	{
		LCS(s1,s2);
		ans.clear();
		go(len1,len2,"");
		set<string>::iterator s;
    	for(s=ans.begin();s!=ans.end();s++)
		{
			cout << *s << "\n";
		}
	}
}

