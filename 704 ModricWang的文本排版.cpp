#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

int n;
int cur;

vector<string> line;
string realinput;

char input[256];

void handleSpace()
{
	int need=line.size()-1;
	int require=n-cur;
	if(need)
	{
		int cnt=require/need;
		int last=require-(need-1)*cnt;
		string out="";
		int i; 
		for(i=0;i<line.size()-1;++i)
		{
			out+=line[i];
			out.insert(out.end(),cnt,' ');
		}
		if(last>cnt)
		{
			out.insert(out.end(),last-cnt,' ');
		}
		out+=line[line.size()-1];
		printf("%s\n", out.c_str());
	}
	else
	{
		string out="";
		out+=line[0];
		printf("%s\n",out.c_str());
	}
	line.clear();
	cur=0;
}

int main()
{
	scanf("%d",&n);
	cur=0;
	while(~scanf("%s",input))
	{
		realinput=input;
		if(realinput.size()+line.size()+cur>n)
		{
			if(cur)
			{
				handleSpace();
				line.push_back(input);
				cur+=realinput.size();
			}
			else
			{
				printf("%s\n",input);
			}
		}
		else
		{
			line.push_back(input);
			cur+=realinput.size();
		}
	}
	if(!line.empty())
	{
		vector<string>::iterator a;
		for(a=line.begin();a!=line.end();a++)
		{
			printf("%s ",(*a).c_str());
		}
	}
}
