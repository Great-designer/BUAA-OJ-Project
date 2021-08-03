#include<stdio.h>

#include<queue>

using namespace std;

int n;
priority_queue<long long> qmax;
priority_queue<long long, vector<long long>, greater<long long> >qmin;
long long tmp;
long long maxM, minM;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		while (!qmax.empty())qmax.pop();
		while (!qmin.empty())qmin.pop();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &tmp);
			qmax.push(tmp), qmin.push(tmp);
		}
		while (!qmax.empty())
		{
			long long a = qmax.top();
			qmax.pop();
			if (qmax.empty())
			{
				minM = a;
				break;
			}
			long long b = qmax.top();
			qmax.pop();
			qmax.push(a * b + 1);
		}
		while (!qmin.empty())
		{
			long long a = qmin.top();
			qmin.pop();
			if (qmin.empty())
			{
				maxM = a;
				break;
			}
			long long b = qmin.top();
			qmin.pop();
			qmin.push(a * b + 1);
		}
		printf("%lld\n", maxM - minM);
	}
}