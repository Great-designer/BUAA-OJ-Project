#include<stdio.h>
#include<string.h>

#include<vector>

using namespace std;

int n,m;
int tmpint;
char Insert[5]="Ins";
char Delete[5]="Del";
char Locate[5]="Loc";
char Getcha[5]="Get";
char operation[5];
int opA,opB;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		vector<int> a;
		int i; 
		for(i=0;i<n;++i)
		{
			scanf("%d",&tmpint);
			a.push_back(tmpint);
		}
		while(m--)
		{
			scanf("%s",operation);
			if(!strcmp(operation,Insert))
			{
				scanf("%d%d",&opA,&opB);
				if(opA>(a.size()+1)||opA<=0)
				{
					printf("Wrong input!\n");
				}
				else
				{
					a.insert(a.begin()+opA-1,opB);
					vector<int>::iterator ni;
					for(ni=a.begin();ni!=a.end();ni++)
					{
						printf("%d ",*ni);
					}
					printf("\n");
				}
			}
			else if(!strcmp(operation,Delete))
			{
				scanf("%d",&opA);
				char mark=0;
				vector<int>::iterator it;
				for(it=a.begin();it!=a.end();++it)
				{
					if(*it==opA)
					{
						mark=1;
						a.erase(it);
						vector<int>::iterator ni;
						for(ni=a.begin();ni!=a.end();ni++)
						{
							printf("%d ",*ni);
						}
						printf("\n");
						break;
					}
				}
				if(!mark)
				{
					printf("Wrong input!\n");
				}
			}
			else if(!strcmp(operation,Locate))
			{
				scanf("%d",&opA);
				char mark=0;
				vector<int>::iterator it=a.begin();
				for(i=0;it+i!=a.end();++i)
				{
					if(*(it+i)==opA)
					{
						mark=1;
						printf("%d\n",++i);
						break;
					}
				}
				if(!mark)
				{
					printf("Wrong input!\n");
				}
			}
			else if(!strcmp(operation,Getcha))
			{
				scanf("%d",&opA);
				vector<int>::iterator it=a.begin();
				if(opA>a.size()||opA<=0)
				{
					printf("Wrong input!\n");
				}
				else
				{
					printf("%d\n",*(it+opA-1));
				}
			}
		}
	}
}
