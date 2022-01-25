#include<stdio.h>
#include<string.h>

struct Matrix
{
	double value[6][6];
};

void init(struct Matrix *a)
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (i != j && i + j != 5)
			{
				a->value[i][j] = 0.25;
			}
		}
	}
}

struct Matrix Mult(struct Matrix *a,struct Matrix *b)
{
	struct Matrix ret;
	memset(ret.value, 0, sizeof(ret.value));
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			for (int k = 0; k < 6; ++k)
			{
				ret.value[i][j] += a->value[i][k] * b->value[k][j];
			}
		}
	}
	return ret;
}

struct Matrix fastpower(int power,struct Matrix *a)
{
	struct Matrix tmp = *a;
	struct Matrix ret;
	memset(ret.value, 0, sizeof(ret.value));
	for (int i = 0; i < 6; ++i)ret.value[i][i] = 1.0;
	while (power)
	{
		if (power & 1)
		{
			ret=Mult(&ret,&tmp);
		}
		tmp=Mult(&tmp,&tmp);
		power >>= 1;
	}
	return ret;
}

struct Vector
{
	double value[6];
};

struct Vector multi(struct Matrix matrix,struct Vector *a)
{
	struct Vector ret;
	memset(ret.value, 0, sizeof(ret.value));
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			ret.value[i] += a->value[j] * matrix.value[j][i];
		}
	}
	return ret;
}

struct Matrix trans;
struct Matrix mul;
struct Vector ans;

int n, k;
double start[6];

int main()
{
	init(&trans);
	while (scanf("%d%d", &n, &k) != EOF)
	{
		--n;
		for (int i = 0; i < 6; ++i)
		{
			if (n == i) start[i] = 100.0;
			else start[i] = 0.0;
		}
		mul=fastpower(k,&trans);
		ans.value[0]=start[0];
		ans.value[1]=start[1];
		ans.value[2]=start[2];
		ans.value[3]=start[3];
		ans.value[4]=start[4];
		ans.value[5]=start[5];
		ans=multi(mul,&ans);
		for (int i = 0; i < 6; ++i)
			printf("%.2f%%%c", ans.value[i], i == 5 ? '\n' : ' ');
	}
}
