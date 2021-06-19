#include<stdio.h>
double sum_grade, sum_point;
int score;
double credit;
int main()
{
	while (scanf("%d%lf", &score, &credit) != EOF)
	{
		if(score >= 60)sum_grade +=  (4.0 - 3.0 * (100.0 - 1.0 * score) * (100.0 - 1.0 * score) / 1600.0) * credit;
		sum_point += credit;
	}
	printf("%.2f\n", sum_grade / sum_point);
	return 0;
}