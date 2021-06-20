#include<iostream>
#include<vector>

using namespace std;

string add="Add";
string del="Del";
string rep="Rep";
string a;
string op;
int opA;
char opB;
int opC;
int n,m;

int main()
{
	while(cin >> n >> m)
	{
		cin >> a;
		vector<char> b;
		int i; 
		for(i=0;i<a.length();++i)
		{
			b.push_back(a[i]);
		}
		while(m--)
		{
			cin >> op;
			if(op==add)
			{
				cin >> opA >> opB;
				b.insert(b.begin()+opA-1,opB);
			}
			else if (op==del)
			{
				cin >> opA >> opC;
				while(opC--)
				{
					b.erase(b.begin()+opA-1);
				}
			}
			else
			{
				cin >> opA >> opB;
				b[opA-1] = opB;
			}
		}
		vector<char>::iterator c;
		for(c=b.begin();c!=b.end();c++)
		{
			cout << *c;
		}
		cout << endl;
	}
} 
