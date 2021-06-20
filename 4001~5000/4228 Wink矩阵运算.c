#include<stdio.h>

long long A[100][100], B[100][100], C[100][100];

int main(void)
{
	int M, N, P, Q;
	int i, j, k;
	////input
	scanf("%d%d", &M, &N);
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%lld", &A[i][j]);
	scanf("%d%d", &P, &Q);
	for (i = 0; i < P; i++)
		for (j = 0; j < Q; j++)
			scanf("%lld", &B[i][j]);
	////input
	////compute
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < Q; j++)
		{
			for (k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	////compute
	////output
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < Q; j++)
		{
			printf("%lld ", C[i][j]);
		}
		printf("\n");
	}
	////output
	return 0;
}