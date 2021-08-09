#include<stdio.h>

#include<queue>

using namespace std;

int m,n;
deque<int> gua;
int ate;
int op;
int xigua;

int main()
{
	while(~scanf("%d",&m))
	{
		while(!gua.empty())
		{
			gua.pop_front();
		}
		while(m--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d",&n);
				while(n--)
				{
					scanf("%d",&xigua);
					gua.push_back(xigua);
				}
			}
			else if(op==2)
			{
				scanf("%d",&n);
				while(n--)
				{
					if(!gua.empty())
					{
						gua.pop_back();
					}
				}
			}
			else if(op==3)
			{
				ate=0;
				scanf("%d",&n);
				while(n--)
				{
					if(!gua.empty())
					{
						if(gua.front()==1)
						{
							++ate;
						}
						gua.pop_front();
					}
				}
				printf("%d\n",ate);
			}
		}
	}
}
