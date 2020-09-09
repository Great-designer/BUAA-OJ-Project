#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include<vector>

using namespace std;

/*****************************************************************
����˼·����������ĸ����㷨
����벻������û��

���һ������û�м��������ǹ�
��ô������ǹ����֮��һ����Ŀ���ǹ���ŵı���
����֮��һ����

��ĳ����ŵ��ǹ����ĳһ���Ƚϴ����
�Ǵ�����ϲ����ͻ��1+3=2+2���־Ͳ��У�

����������ǹ���Ŷ����ж�����������������Ҫ���ж�
�Ϳ�����Ϊ:
�ڸ�����ÿ�����ڷǽ�������ǹ��ĸ��ӣ�������һ�������
ʹ�ø��ԵĺͲ�������ܵĶ�Ӧ������ı���

Ҳ����˵������ȫƴ���Ǹ���
��������ĳ�����ʺܵͣ����Լ��ξͼ���Ϊ0

ʣ�µĶ�άǰ׺�;Ͳ�̫��˵�˾���O(1)��ѯ����������͵�Ҫ��

[x1,y1][x2,y2]���������һ����v���Ա�ʾΪ
��ĳ��a�����[x1,y1][x2+1,y2+1]����v
Ȼ��[x1,y2+1][x2+1][y1]��-v��Ȼ��a�����Ӧǰ׺�;Ϳ���

dp[i][j]=dp[i-1][j]+dp[i][j-1]+a[i][j]
ĳ�����ӵ�[x,y]ֵ�������
dp[x][y]+dp[x-1][y-1]-dp[x][y-1]-dp[x-1][y]��ʾ(�Ӿ���ĺ�ֵ)
*****************************************************************/

long long map[1000010];
vector<long long> counter[1000010],a[1000010];

void write(long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

long long read()
{
	long long k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

long long n,m,t,tmpint;
long long x1,y1,x2,y2,v;

int main()
{
	n = read();
	m = read();
	t = read();
	int i;
	for(i = 0; i <= n + 1; ++i)
	{
		a[i].resize(m + 2);
		counter[i].resize(m + 2);
	}
	srand(time(0));
	for(i = n * m; i > 0; --i)
	{
		map[i] = (rand() * 1ll << 24ll) ^ (rand() << 8ll) ^ (rand() % (1ll << 8));
	}
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= m; ++j)
		{
			tmpint = read();
			a[i][j] = map[tmpint];
		}
	}
	while (t--)
	{
		x1 = read();
		y1 = read();
		x2 = read();
		y2 = read();
		v = read();
		++x2;
		++y2;
		long long w = map[v];
		counter[x1][y1] += w;
		counter[x1][y2] -= w;
		counter[x2][y1] -= w;
		counter[x2][y2] += w;
	}
	long long res = 0;
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= m; ++j)
		{
			counter[i][j] += counter[i - 1][j] + counter[i][j - 1] - counter[i - 1][j - 1];
			res += (counter[i][j] % a[i][j]) != 0;
		}
	}
	write(res);
}
