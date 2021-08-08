#include<iostream>
#include<algorithm>

using namespace std;

long long a[3000100];
long long A, B, C, k;

void buildArray()
{
	int i;
	for (i = 2; i <= 3000000; ++i)
	{
		a[i] = ((1LL * a[i - 1] * A ^ B) + C) % 1000000007;
	}
}

int main()
{
	while (cin >> A >> B >> C >> a[1] >> k)
	{
		buildArray();
		nth_element(a + 1, a + k, a + 3000000 + 1);
		cout << a[k] << endl;
	}
}
