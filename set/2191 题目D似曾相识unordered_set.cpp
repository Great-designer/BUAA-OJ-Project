#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<string>
#include<iterator>

using namespace std;

unordered_set<string>a;
unordered_set<string>::iterator pointer;
int n, m;
int tmpInt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	while (n--)
	{
		string tmp = "";
		for (int i = 1; i <= m; ++i)
		{
			cin >> tmpInt;
			tmp += to_string(tmpInt) + "#";
		}
		pointer = a.find(tmp);
		if (pointer != a.end())cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			a.insert(tmp);
		}
	}
}
