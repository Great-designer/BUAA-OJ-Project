#include<iostream>

using namespace std;

int n;
string s;

int main()
{
	while(cin>>n>>s)
	{
		int index = s.find_first_of('1',0);
		if(index==-1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int count=0;
		index++;
		for(int i = index; i<s.length(); ++i)if(s[i]=='0')++count;
		if(count>=7)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
