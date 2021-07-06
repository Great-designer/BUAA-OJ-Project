#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

const double PI = acos(-1.0);

struct complex
{
	double r, i;
	complex(double _r = 0, double _i = 0)
	{
		r = _r;
		i = _i;
	}
	complex operator +(const complex& b)
	{
		return complex(r + b.r, i + b.i);
	}
	complex operator -(const complex& b)
	{
		return complex(r - b.r, i - b.i);
	}
	complex operator *(const complex& b)
	{
		return complex(r * b.r - i * b.i, r * b.i + i * b.r);
	}
};

void change(struct complex y[], int len)
{
	int i, j, k;
	for (i = 1, j = len / 2; i < len - 1; i++)
	{
		if (i < j)
		{
			struct complex temp=y[i];
			y[i]=y[j];
			y[j]=temp;
		}
		k = len / 2;
		while (j >= k)
		{
			j -= k;
			k /= 2;
		}
		if (j < k)j += k;
	}
}

void fft(struct complex y[], int len, int on)
{
	change(y, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for (int j = 0; j < len; j += h)
		{
			complex w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				complex u = y[k];
				complex t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (on == -1)
		for (int i = 0; i < len; i++)
			y[i].r /= len;
}

struct complex x1[400040];
int a[400040 / 4];
long long num[400040];//100000*100000会超int
long long sum[400040];

int compare(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int T;
	int n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			num[a[i]]++;
		}
		qsort(a,n,sizeof(int),compare);
		int len1 = a[n - 1] + 1;
		int len = 1;
		while (len < 2 * len1)len <<= 1;
		for (int i = 0; i < len1; i++)
			x1[i] = complex(num[i], 0);
		for (int i = len1; i < len; i++)
			x1[i] = complex(0, 0);
		fft(x1, len, 1);
		for (int i = 0; i < len; i++)
			x1[i] = x1[i] * x1[i];
		fft(x1, len, -1);
		for (int i = 0; i < len; i++)
			num[i] = (long long)(x1[i].r + 0.5);
		len = 2 * a[n - 1];
		//减掉取两个相同的组合
		for (int i = 0; i < n; i++)
			num[a[i] + a[i]]--;
		//选择的无序，除以2
		for (int i = 1; i <= len; i++)
		{
			num[i] /= 2;
		}
		sum[0] = 0;
		for (int i = 1; i <= len; i++)
			sum[i] = sum[i - 1] + num[i];
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += sum[len] - sum[a[i]];
			//减掉一个取大，一个取小的
			cnt -= (long long)(n - 1 - i) * i;
			//减掉一个取本身，另外一个取其它
			cnt -= (n - 1);
			//减掉大于它的取两个的组合
			cnt -= (long long)(n - 1 - i) * (n - i - 2) / 2;
		}
		//总数
		long long tot = (long long)n * (n - 1) * (n - 2) / 6;
		printf("%.6lf\n", (double)cnt / tot);
	}
	return 0;
}