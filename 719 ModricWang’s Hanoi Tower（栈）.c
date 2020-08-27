#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hanoi
{
	int tower[110];
	int top;
	char name;
};

struct Hanoi a,b,c;

void move(struct Hanoi *a,struct Hanoi *b)
{
	if(a->top!=0)
	{
		int k=a->tower[a->top-1];
		a->top--;
		b->tower[b->top]=k;
		b->top++;
		printf("%c --> %c\n",a->name,b->name);
	}
}

void simuHanoi(int n,struct Hanoi *a,struct Hanoi *b,struct Hanoi *c)
{
	if(n)
	{
		simuHanoi(n-1,&(*a),&(*b),&(*c));
		move(&(*a),&(*b));
		simuHanoi(n-1,&(*c),&(*b),&(*a));
		move(&(*b),&(*c));
		simuHanoi(n-1,&(*a),&(*b),&(*c));
	}
}

int main()
{
	a.name='A';
	b.name='B';
	c.name='C';
	int n;
	while(~scanf("%d", &n))
	{
		c.top=0;
		int i;
		for(i=n;i;--i)
		{
			a.tower[a.top]=i;
			a.top++;
		}
		simuHanoi(n,&a,&b,&c);
	}
}
