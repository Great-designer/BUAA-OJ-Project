#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int type[107], wide[107], sp[107][2], row, col, n;
char title[107][107], typeString[107];

struct table
{
	union attr
	{
		char varchar[107];
		double real;
		int date;
		int intNum;
	} A;
	char rawData[107];
	int length;
};

struct table t[1007][107];

void readTable()
{

	int i, j, y, m, d;
	scanf("%d %d", &row, &col);
	for (i = 0; i < col; i++)
	{
		scanf("%s", title[i]);
		if (strlen(title[i]) > wide[i])
			wide[i] = (int)strlen(title[i]);
	}
	for (i = 0; i < col; i++)
	{
		scanf("%s", typeString);
		if (strcmp(typeString, "INT") == 0)
			type[i] = 0;
		else if (strcmp(typeString, "REAL") == 0)
			type[i] = 1;
		else if (strcmp(typeString, "VARCHAR") == 0)
			type[i] = 2;
		else
			type[i] = 3;
	}
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			scanf("%s", t[i][j].rawData);
			t[i][j].length = (int)strlen(t[i][j].rawData);
			if (t[i][j].length > wide[j])
				wide[j] = t[i][j].length;
			switch (type[j])
			{
				case 0:
					sscanf(t[i][j].rawData, "%d", &t[i][j].A.intNum);
					break;
				case 1:
					sscanf(t[i][j].rawData, "%lf", &t[i][j].A.real);
					break;
				case 2:
					sscanf(t[i][j].rawData, "%s", t[i][j].A.varchar);
					break;
				case 3:
					sscanf(t[i][j].rawData, "%d-%d-%d", &y, &m, &d);
					t[i][j].A.date = d + m * 100 + y * 10000;
				default:
					break;
			}
		}
}

void readSP()
{
	int i;
	char colName[107];
	while (~scanf("%s %d", colName, &sp[n][1]))
	{
		for (i = 0; i < col; i++)
			if (strcmp(colName, title[i]) == 0)
			{
				sp[n][0] = i;
				break;
			}
		n++;
	}
}

int cmp(const void *a, const void *b)
{
	struct table *t1 = (struct table *)a, *t2 = (struct table *)b;
	int i, c, sgn, ret = 0;
	for (i = 0; i < n; i++)
	{
		c = sp[i][0];
		sgn = sp[i][1];
		switch (type[c])
		{
			case 2:
				ret = sgn * strcmp(t1[c].A.varchar, t2[c].A.varchar);
				break;
			case 0:
				ret = sgn * (t1[c].A.intNum - t2[c].A.intNum);
				break;
			case 1:
				if (t1[c].A.real - t2[c].A.real > 0)
					ret = sgn * 1;
				else if (t1[c].A.real - t2[c].A.real < 0)
					ret = sgn * -1;
				else
					ret = 0;
				break;
			case 3:
				ret = sgn * (t1[c].A.date - t2[c].A.date);
			default:
				break;
		}
		if (ret != 0)
			return ret;
	}
	return 0;
}

void printTable()
{
	char format[107];
	int i, j;
	putchar('|');
	for (j = 0; j < col; j++)
	{
		sprintf(format, "%%%ds", wide[j]);
		printf(format, title[j]);
		putchar('|');
	}
	putchar('\n');
	for (i = 0; i < row; i++)
	{
		putchar('|');
		for (j = 0; j < col; j++)
		{
			sprintf(format, "%%%ds", wide[j]);
			printf(format, t[i][j].rawData);
			putchar('|');
		}
		putchar('\n');
	}
}

int main()
{
	readTable();
	readSP();
	qsort(t, row, sizeof(*t), cmp);
	printTable();
	return 0;
}