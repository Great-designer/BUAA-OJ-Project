#include<stdio.h>

#include<map>

using namespace std;

int n;
int tmpInt;

int main()
{
	while(~scanf("%d",&n))
	{
		map<int,pair<int,int> > counterMap;
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&tmpInt);
			map<int,pair<int,int> >::iterator search=counterMap.find(tmpInt);
			if(search==counterMap.end())
			{
				counterMap.insert(make_pair(tmpInt,make_pair(i,1)));
			}
			else
			{
				++search->second.second;
			}
		}
		int result=0;
		int maxCount=0;
		int minIndex=10001;
		map<int,pair<int,int> >::iterator a;
		for(a=counterMap.begin();a!=counterMap.end();a++)
		{
			if((*a).second.second>maxCount||((*a).second.second==maxCount&&(*a).second.first<minIndex))
			{
				result=(*a).first;
				maxCount=(*a).second.second;
				minIndex=(*a).second.first;
			}
		}
		printf("%d\n",result);
	}
}
