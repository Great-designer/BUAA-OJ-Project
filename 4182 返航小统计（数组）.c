#include<stdio.h>

struct student
{
	int id;
	int hour;
	int min;
};

struct student A[150][150];
int B[150];

int main()
{
	int date;
	scanf("%d",&date);
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int id,day,hour,min;
		scanf("%d%d%d:%d",&id,&day,&hour,&min);
		A[day][B[day]].id=id;
		A[day][B[day]].hour=hour;
		A[day][B[day]].min=min;
		B[day]++;
	}
	for(i=0;i<B[date];i++)
	{
		printf("%08d %02d:%02d\n",A[date][i].id,A[date][i].hour,A[date][i].min);
	}
	printf("%d\n",B[date]);
}