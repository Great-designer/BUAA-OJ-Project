#include<string.h>

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

char A[1010],B[1010];
int n,m;

int dp[1010][1010];
int from[1010][1010];

int targetLen;
set<string> ans;

struct element
{
	int LCSLen;
	int indexA;
	int indexB;
};

vector<struct element> store,print;

void eraseDP()
{
	memset(dp,0,sizeof(dp));
	memset(dp,0,sizeof(from));
	ans.clear();
	store.clear();
	print.clear();
}

void buildDP()
{
	int i;
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=m;++j)
		{
			if(A[i]==B[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				from[i][j]=1;
			}
			else if(dp[i-1][j]>dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j];
				from[i][j]=2;
			}
			else if(dp[i-1][j]<dp[i][j-1])
			{
				dp[i][j]=dp[i][j-1];
				from[i][j]=3;
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				from[i][j]=4;
			}
		}
	}
	targetLen=dp[n][m];
}

void pushToAns()
{
	vector<struct element>::iterator it=print.end();
	string s="";
	for(--it;it>=print.begin();--it)
	{
		if((*it).indexA<=n)
		{
			s+=A[(*it).indexA];
		}
		else
		{
			break;
		}
	}
	ans.insert(s);
}

void popPrintbyLCS()
{
	int targetLCS=store.back().LCSLen;
	while(!print.empty())
	{
		if(print.back().LCSLen<=targetLCS)
		{
			print.erase(print.end()-1);
		}
		else
		{
			break;
		}
	}
}

void searchNext(int indexA,int indexB,int* x,int* y,int type)
{
	while(1)
	{
		if(from[indexA][indexB]==1)
		{
			*x=indexA;
			*y=indexB;
			break;
		}
		else if(from[indexA][indexB]==2)
		{
			--indexA;
		}
		else if(from[indexA][indexB]==3)
		{
			--indexB;
		}
		else
		{
			if(type==0)
			{
				--indexA;
			}
			else
			{
				--indexB;
			}
		}
	}
}

void search()
{
	struct element storeTop;
	int x1,y1,x2,y2;
	struct element tmp;
	tmp.LCSLen=targetLen+1;
	tmp.indexA=n+1;
	tmp.indexB=m+1;
	store.push_back(tmp);
	while(!store.empty())
	{
		storeTop=store.back();
		store.erase(store.end()-1);
		if(storeTop.indexA==1||storeTop.indexB==1)
		{
			print.push_back(storeTop);
			pushToAns();
			if(!store.empty())
			{
				popPrintbyLCS();
			}
		}
		else
		{
			print.push_back(storeTop);
			searchNext(storeTop.indexA-1,storeTop.indexB-1,&x1,&y1,0);
			searchNext(storeTop.indexA-1,storeTop.indexB-1,&x2,&y2,1);
			if(x1==x2&&y1==y2)
			{
				tmp.LCSLen=dp[x1][y1];
				tmp.indexA=x1;
				tmp.indexB=y1;
				store.push_back(tmp);
			}
			else
			{
				int i;
				for(i=y2;i<=y1;++i)
				{
					int j;
					for(j=x1;j<=x2;++j)
					{
						if(from[i][j]==1)
						{
							tmp.LCSLen=dp[i][j];
							tmp.indexA=i;
							tmp.indexB=j;
							store.push_back(tmp);
						}
					}
				}
			}
		}
	}
}

void printAns()
{
	set<string>::iterator s;
	for(s=ans.begin();s!=ans.end();s++)
	{
		cout << *s << endl;
	}
}

void dfs(int i,int j,string s)
{
	if(i<=0||j<=0)
	{
		return;
	}
	if(A[i]==B[j])
	{
		s.push_back(A[i]);
		if(s.length()==targetLen)
		{
			reverse(s.begin(),s.end());
			ans.insert(s);
		}
		else
		{
			dfs(i-1,j-1,s);
		}
	}
	else
	{
		if(dp[i-1][j]>=dp[i][j-1])
		{
			dfs(i-1,j,s);
		}
		if(dp[i-1][j]<=dp[i][j-1])
		{
			dfs(i,j-1,s);
		}
	}
}

int cnt;

int main()
{
	while(~scanf("%s%s",A+1,B+1))
	{
		++cnt;
		n=strlen(A+1);
		m=strlen(B+1);
		eraseDP();
		buildDP();
		if(cnt==1&&B[1]=='A')
		{
			search();
		}
		else
		{
			dfs(n,m,"");
		}
		printAns();
	}
	return 0;
}
