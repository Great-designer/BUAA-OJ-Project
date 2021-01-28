#include<stdio.h>
#include<string.h>
#include<unordered_set>

using namespace std;

unordered_set<int> a;

int n,m;
int input;

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<n;++i)
	{
		scanf("%d",&input);
		a.insert(input);
	}
	for(i=0;i<m;++i)
	{
		scanf("%d",&input);
		printf("%s\n",a.count(input)?"Yes":"No");
	}
}
