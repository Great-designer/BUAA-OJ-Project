#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>

using namespace std;

string output;
char c;

int main()
{
	while(~(c=getchar()))
	{
		output.push_back(c);
	}
	string real="";
	string tmp="";
	int i;
	for(i=0;i<output.size();++i)
	{
		tmp.push_back(output[i]);
		if(*tmp.rbegin()=='.'||*tmp.rbegin()=='?'||*tmp.rbegin()=='!')
		{
			int start=0;
			while(isspace(tmp[start]))
			{
				start++;
			}
			if(islower(tmp[start]))
			{
				tmp[start]=toupper(tmp[start]);
			}
			real+=tmp;
			tmp="";
		}
	}
	puts(real.c_str());
}
