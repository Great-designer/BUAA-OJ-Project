#include<stdio.h>
#include<string.h>

char s1[110][3];
char s2[10][3];
int next[10];
int len1;

void get_s2(long long a)
{
	for (int i = 0; i < 8; ++i)
	{
		int x = a % 256;
		sprintf(s2[i], "%02X\0", x);
		a /= 256;
	}
}

void getNext()
{
	int t = next[0] = -1;
	int j = 0;
	while (j < 8)
	{
		//仅做单次匹配那么条件为j < len - 1即可
		//如果想完成多次匹配,这里的条件需要改成len
		if (t < 0 || !strcmp(s2[j],s2[t]))next[++j] = ++t;
		else t = next[t];
	}
}

void KMP()  //KMP
{
	int j = 0, s = 0;
	while (j < len1 && s < 8)
	{
		if (s == -1 || !strcmp(s2[s],s1[j]))
		{
			++j, ++s;
		}
		else s = next[s];
		if (s == 8)printf("%d ", j - 8), s = next[s];
	}
}

double x;

int main()
{
	scanf("%d", &len1);
	for (int i = 0; i < len1; ++i)
		scanf("%s", s1[i]);
	scanf("%lf", &x);
	long long* b = (long long*)&x;
	get_s2(*b);
	getNext();
	KMP();
}