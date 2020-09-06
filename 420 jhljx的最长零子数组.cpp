#include<stdio.h>
#include<map>

using namespace std; 

map<int,int> m;

int main()
{
	int n,tp;
	while(~scanf("%d",&n))
	{
		m.clear();
		if(n==1)
		{
			scanf("%d",&tp);
			printf("0\n");
			continue;
		}
		int sum=0,ans=0;
		m[0]=-1;
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&tp);
			if(tp+1) 
			{
				++sum;
			}
			else
			{
				--sum;
			}
			map<int,int>::iterator it=m.find(sum);
			map<int,int>::iterator E=m.end();
			if(it!=E)
			{
				int d=i-it->second;
				if(d>ans)
				{
					ans=d;
				}
			}
			else
			{
				m[sum]=i;
			}
		}
		printf("%d\n",ans);
	}
}

