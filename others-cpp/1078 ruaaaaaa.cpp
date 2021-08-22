#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
int a[10010], b[10010], c[2 * 10010 + 5];
string aa, bb;

string bigIntegerMul(string s1, string s2)
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	int len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < len1; ++i)a[i] = s1[len1 - 1 - i] - '0';
	for (int i = 0; i < len2; ++i)b[i] = s2[len2 - 1 - i] - '0';
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			c[i + j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < 10010 * 2; ++i)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	string result = "";
	int temp;
	for (temp = 10010 * 2; temp >= 0; temp--)
		if (c[temp] != 0)break;
	for (; temp >= 0; temp--)result += (c[temp] + '0');
	if (result.empty())result += "0";
	return result;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> aa >> bb;
		cout << bigIntegerMul(aa, bb) << endl;
	}
	return 0;
}
