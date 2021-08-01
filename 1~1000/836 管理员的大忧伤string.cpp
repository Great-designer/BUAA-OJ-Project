#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

string a;

char handle()
{
	if (a.length() < 5)return 0;
	if (!(isdigit(a[0]) && isdigit(a[1]) && isdigit(a[2]) && isdigit(a[3]) && isspace(a[4]))) return 0;
	a = a.replace(0, 5, "");
	int pos;
	if ((pos = a.find(" ")) == a.npos)return 0;
	a = a.replace(0, pos + 1, "");
	if ((pos = a.find(" ")) != a.npos)return 0;
	return 1;
}

int main()
{
	while (getline(cin, a))
	{
		if (a.empty())continue;
		cout << (handle() ? "meng xin bao zhao!" : "qiu qiu ni le, gai ming pian ba") << endl;
	}
}
