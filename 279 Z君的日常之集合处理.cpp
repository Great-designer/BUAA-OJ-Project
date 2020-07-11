#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

char tmp[3];
char op;
int t,n,m;
int tmpint;

int main()
{
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%s%d%d",tmp,&n,&m);
			op=tmp[0];
			vector<int> a,b;
			int i;
			for(i=0;i<n;++i)
			{
				scanf("%d",&tmpint);
				a.push_back(tmpint);
			}
			for(i=0;i<m;++i)
			{
				scanf("%d",&tmpint);
				b.push_back(tmpint);
			}
			sort(a.begin(),a.end());
			sort(b.begin(),b.end());
			if(op=='+')
			{
				vector<int> c;
				set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c),less<int>());
				std::vector<int>::iterator m;
				for(m=c.begin();m!=c.end();m++)
				{
					printf("%d ",*m);
				}
				printf("\n");
			}
			else
			{
				vector<int> c;
				set_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c),less<int>());
				if(!c.empty())
				{
					std::vector<int>::iterator m;
					for(m=c.begin();m!=c.end();m++) 
					{
						printf("%d ",*m);
					} 
					printf("\n");
				}
				else
				{
					printf("empty\n");
				}
			}
		}
	}
}
