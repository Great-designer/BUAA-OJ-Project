#include<stdio.h>

#include<map>

using namespace std;

map<int,int>a;

int n,tmp;

int main()
{
    while(~scanf("%d",&n))
	{
        a.clear();
        while(n--)
		{
			scanf("%d",&tmp);
			a[tmp]++;
		}
		map<int,int>::iterator it;
        for(it=a.begin();it!=a.end();++it)
		{
            printf("[%d] ",it->first);
        }
        puts("");
        int cnt=0,target=a.size();
        while(cnt!=target)
		{
			map<int,int>::iterator it;
            for(it=a.begin();it!=a.end();++it)
			{
                if(it->second==1)
				{
					cnt++;
				}
                if(it->second>0)
				{
					printf("# ");
				}
                else
				{
					printf("  ");
				}
                it->second--;
            }
            puts("");
        }
        puts("");
    }
}
