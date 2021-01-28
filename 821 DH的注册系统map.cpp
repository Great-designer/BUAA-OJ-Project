#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

char s[33];

string a;
map<string,long long> reglist;

int n;

int main()
{
	while(~scanf("%d",&n))
	{
		reglist.clear();
		while(n--)
		{
			scanf("%s",s);
			a=s;
			if(reglist.count(a))
			{
				printf("%s%lld\n",s,reglist[a]);
				reglist[a]++;
			}
			else
			{
				puts("OK");
				reglist.insert(make_pair(a,1));
			}
		}
	}
}
