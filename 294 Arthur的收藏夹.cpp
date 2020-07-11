#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;

int t;
int m,n;
int tmpint;

int main()
{
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			set<int>Arthur,Thor;
			int i;
			for(i=0;i<m;++i)
			{
				scanf("%d",&tmpint);
				Arthur.insert(tmpint);
			}
			for(i=0;i<n;++i)
			{
				scanf("%d",&tmpint);
				Thor.insert(tmpint);
			}
			set<int>lalala;
			set_difference(Arthur.begin(),Arthur.end(),Thor.begin(),Thor.end(),inserter(lalala,lalala.begin()));
			if(!lalala.size())
			{
				printf("LOSER!\n");
			} 
			else
			{
				printf("%d\n",lalala.size());
				set<int>::iterator it;
				for(it=lalala.begin();it!=lalala.end();it++)
				{
					printf("%d ",*it);
				}
				putchar('\n');
			}
		}
	}
}
