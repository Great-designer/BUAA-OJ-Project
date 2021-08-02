#include<stdio.h>

struct stackName
{
	int tower[40];
	int top;
	char name;
};

struct stackName Hanoi[3];

int T;
int n;
long long step;
long long current;

int main()
{
	while(~scanf("%d",&n))
	{
		Hanoi[0].name='A';
		int i;
		for(i=0;i<n;++i)
		{
			Hanoi[0].tower[Hanoi[0].top]=n-i;
			Hanoi[0].top++;
		}
		if(n%2==0)
		{
			Hanoi[1].name='B';
			Hanoi[2].name='C';
		}
		else
		{
			Hanoi[1].name='C';
			Hanoi[2].name='B';
		}
		step=((long long)1<<n)-1;
		current=0;
		i=0;
		int curPlace;
		while(current<step)
		{
			curPlace=Hanoi[i%3].tower[Hanoi[i%3].top-1];
			Hanoi[i%3].top--;
			Hanoi[(i+1)%3].tower[Hanoi[(i+1)%3].top]=curPlace;
			Hanoi[(i+1)%3].top++;
			++current;
			printf("%c -> %c\n",Hanoi[i%3].name,Hanoi[(i+1)%3].name);
			++i;
			if(i>3)
			{
				i%=3;
			}
			if(current<step)
			{
				if(Hanoi[(i+1)%3].top==0||((!(Hanoi[(i-1)%3].top==0))&&Hanoi[(i+1)%3].tower[Hanoi[(i+1)%3].top-1]>Hanoi[(i-1)%3].tower[Hanoi[(i-1)%3].top-1]))
				{
					curPlace=Hanoi[(i-1)%3].tower[Hanoi[(i-1)%3].top-1];
					Hanoi[(i-1)%3].top--;
					Hanoi[(i+1)%3].tower[Hanoi[(i+1)%3].top]=curPlace;
					Hanoi[(i+1)%3].top++;
					++current;
					printf("%c -> %c\n",Hanoi[(i-1)%3].name,Hanoi[(i+1)%3].name);
				}
				else
				{
					curPlace=Hanoi[(i+1)%3].tower[Hanoi[(i+1)%3].top-1];
					Hanoi[(i+1)%3].top--;
					Hanoi[(i-1)%3].tower[Hanoi[(i-1)%3].top]=curPlace;
					Hanoi[(i-1)%3].top++;
					++current;
					printf("%c -> %c\n",Hanoi[(i+1)%3].name,Hanoi[(i-1)%3].name);
				}
			}
		}
		printf("Finished!\n");
		for(i=0;i<3;++i)
		{
			while(!(Hanoi[i].top==0))
			{
				Hanoi[i].top--;
			}
		}
	}
}
