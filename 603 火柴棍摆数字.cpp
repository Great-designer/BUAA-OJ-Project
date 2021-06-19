#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const LL INF = (1uLL << 63) - 1;
const LL mod = 1000000007;
const int N = 1e5 + 5;
const double Pi = acos(-1.0);
const int maxn = 2e5 + 5;
int main()
{
#ifdef local
	freopen("in", "r", stdin);
#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n==4)
		{
			puts("11 4");
			continue;
		}
		string big = "";
		while(n > 6)
		{
			big =big + "1";
			n -= 2;
		}
		if(n==6)
		{
			printf("111");
			cout<<big<<" ";
			printf("77");
			cout<<big<<endl;
		}
		else if(n==5)
		{
			printf("71");
			cout<<big<<" ";
			printf("17");
			cout<<big<<endl;
		}
	}
}