#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;

map<int,int> freq;

int compare(const void*a,const void*b)
{
	return (int*)a-(int*)b;
}

int a[15];

int main()
{
	while(~scanf("%d",&a[0]))
	{
		freq.clear();
		int i;
		for(i=1;i<13;++i)
		{
			scanf("%d",a+i);
		}
		qsort(a,13,sizeof(int),compare);
		for(i=0;i<13;++i)
		{
			freq[a[i]]++;
		}
		int duplicatecnt=0,singlecnt=0;
		map<int,int>::iterator it;
		for(it=freq.begin();it!=freq.end();++it)
		{
			if(it->second>=2)
			{
				duplicatecnt+=it->second-2;
			}
			else
			{
				singlecnt++;
			}
		}
		if(duplicatecnt>=singlecnt)
		{
			printf("%d\n",duplicatecnt);
		}
		else
		{
			printf("%d\n",duplicatecnt+((singlecnt-duplicatecnt-1)>>1));
		}
	}
}
