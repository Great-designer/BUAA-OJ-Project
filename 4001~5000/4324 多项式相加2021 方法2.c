#include<stdio.h>

long long poly_f_coe[100010];
long long poly_f_pow[100010];
long long poly_g_coe[100010];
long long poly_g_pow[100010];

long long poly_ans_coe[200020];
long long poly_ans_pow[200020];

int main()
{
	int n, m, i;
	int current_i = 0;
	int current_j = 0;
	int current_k = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &poly_f_coe[i], &poly_f_pow[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%lld%lld", &poly_g_coe[i], &poly_g_pow[i]);
	}
	while (current_i < n || current_j < m)
	{
		if (current_i < n)
		{
			if (current_j < m)
			{
				if (poly_f_pow[current_i] > poly_g_pow[current_j])
				{
					poly_ans_coe[current_k] = poly_f_coe[current_i];
					poly_ans_pow[current_k] = poly_f_pow[current_i];
					current_k++;
					current_i++;
				}
				else if (poly_f_pow[current_i] < poly_g_pow[current_j])
				{
					poly_ans_coe[current_k] = poly_g_coe[current_j];
					poly_ans_pow[current_k] = poly_g_pow[current_j];
					current_k++;
					current_j++;
				}
				else
				{
					poly_ans_coe[current_k] = poly_f_coe[current_i] + poly_g_coe[current_j];
					poly_ans_pow[current_k] = poly_f_pow[current_i];
					current_k++;
					current_i++;
					current_j++;
				}
			}
			else
			{
				poly_ans_coe[current_k] = poly_f_coe[current_i];
				poly_ans_pow[current_k] = poly_f_pow[current_i];
				current_k++;
				current_i++;
			}
		}
		else
		{
			poly_ans_coe[current_k] = poly_g_coe[current_j];
			poly_ans_pow[current_k] = poly_g_pow[current_j];
			current_k++;
			current_j++;
		}
	}
	for (i = 0; i < current_k; i++)
	{
		if (poly_ans_coe[i] != 0)
		{
			if (i != current_k - 1)
			{
				printf("%d %d ", poly_ans_coe[i], poly_ans_pow[i]);
			}
			else
			{
				printf("%d %d\n", poly_ans_coe[i], poly_ans_pow[i]);
			}
		}
	}
	return 0;
}