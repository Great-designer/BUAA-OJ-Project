#include<stdio.h>
#include<string.h>

int q[30956];
int front,rear;

char input[10];
char offer[7]="offer";
int op;
char poll[7]="poll";

int main()
{
	while(~scanf("%s",input))
	{
		if(!strcmp(input,offer))
		{
			scanf("%d",&op);
			if((rear-front)>=20)
			{
				puts("fool!");
			}
			else
			{
				q[rear]=op;
				rear++;
			}
		}
		else if(!strcmp(input,poll))
		{
			if(front==rear)
			{
				puts("fool!");
			}
			else
			{
				front++;
			}
		}
		else
		{
			if(front==rear)
			{
				puts("fool!");
			}
			else
			{
				printf("%d\n",q[front]);
			}
		}
	}
}
