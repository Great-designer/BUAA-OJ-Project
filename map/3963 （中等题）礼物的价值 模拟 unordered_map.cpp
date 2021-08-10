#include<string.h>

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int T;
int n;
string s;
string a[10010];
long long cash, num, divide;
long long check_in[10010];
long long check_out[10010];
unordered_map<string, int> aa;

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		aa.clear();
		memset(check_in, 0, sizeof(check_in));
		memset(check_out, 0, sizeof(check_out));
		for(int i = 1; i <= n; ++i) cin >> a[i], aa[a[i]] = i;
		for(int i = 1; i <= n; ++i)
		{
			cin >> s;
			cin >> cash >> num;
			if(num == 0) continue;
			divide = cash / num;
			check_out[aa[s]] += divide * num;
			while (num--)
				cin >> s, check_in[aa[s]] += divide;
		}
		for(int i = 1; i <= n; ++i)
			cout << a[i] << " " << check_in[i] - check_out[i] << endl;
		cout << endl;
	}
}
