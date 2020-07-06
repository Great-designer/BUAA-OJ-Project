#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<vector>

using namespace std;

char sorted;
char Add[4]="Add";
char Del[4]="Del";
char Sum[4]="Sum";
char op[5];
int tmpint;
int n;
long long result;

int main()
{
	while(~scanf("%d",&n))
	{
		vector<int> a;
		sorted=1;
		while(n--)
		{
			scanf("%s",op);
			if(!strcmp(op,Add))
			{
				scanf("%d",&tmpint);
				a.push_back(tmpint);
				sorted=0;
			}
			else if(!strcmp(op,Del))
			{
				if(!sorted)
				{
					sort(a.begin(),a.end());
					sorted=1;
				}
				scanf("%d",&tmpint);
				vector<int>::iterator it;
				for(it=a.begin();it!=a.end();++it)
				{
					if(*it==tmpint)
					{
						a.erase(it);
						break;
					}
				}
			}
			else if(!strcmp(op,Sum))
			{
				result=0;
				if(!sorted)
				{
					sort(a.begin(),a.end());
					sorted=1;
				}
				int i;
				for(i=2;i<a.size();i+=5)
				{
					result+=(long long)a[i];
				}
				printf("%lld\n",result);
			}
		}
	}
}
