#include<iostream>
#include<string>

using namespace std;

bool cmp(string a,string b)
{
	string a1=a.substr(0,a.size()/2);
	string a2=a.substr(a.size()/2,a.size()-a.size()/2);
	string b1=b.substr(0,b.size()/2);
	string b2=b.substr(b.size()/2,b.size()-b.size()/2);
	if(a1.size()&1)
	{
		if((a1==b1&&a2==b2)||(a1==b2&&a2==b1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if((cmp(a1,b1)&&cmp(a2,b2))||(cmp(a1,b2)&&cmp(a2,b1)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

string a,b;

int main()
{
	while(cin>>a>>b)
	{
		if(a.size()&1)
		{
			if(a==b)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else
		{
			if(cmp(a,b))
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
}

