#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int cnt[256];
string s;
int res, len, Left, i;

int main()
{
	while (cin >> s)
	{
		memset(cnt, 0, sizeof(cnt));
		res = Left = 0;
		int pos = s.find("\"");
		s = s.substr(pos + 1, s.length() - pos - 1);
		pos = s.find("\"");
		s = s.substr(0, pos);
		for (i = 0; i < s.length(); ++i)
		{
			if (cnt[s[i]] == 0 || cnt[s[i]] < Left)
				res = max(res, i - Left + 1);
			else
				Left = cnt[s[i]];
			cnt[s[i]] = i + 1;
		}
		printf("%d\n", res);
	}
}