#include<stdio.h>
 
int main()
{
	int n,a,b,c;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c==0)
			{
				printf("QWQ\n");
			}
			else
			{
				if(b==1||b==3||b==5||b==7||b==8||b==10)
				{
					if(c<31)
					{
						printf("%d %d %d\n",a,b,c+1);
					}
					else if(c==31)
					{
						printf("%d %d %d\n",a,b+1,1);
					}
					else
					{
						printf("QWQ\n");
					}
				}
				else if(b==12)
				{
					if(c<31)
					{
						printf("%d %d %d\n",a,b,c+1);
					}
					else if(c==31)
					{
						printf("%d %d %d\n",a+1,1,1);
					}
					else
					{
						printf("QWQ\n");
					}
				}
				else if(b==2)
				{
					if(((a%4==0)&&((a%100)!=0))||(a%400==0))
					{
						if(c<29)
						{
							printf("%d %d %d\n",a,b,c+1);
						}
						else if(c==29)
						{
							printf("%d %d %d\n",a,b+1,1);
						}
						else
						{
							printf("QWQ\n");
						}
					}
					else
					{
						if(c<28)
						{
							printf("%d %d %d\n",a,b,c+1);
						}
						else if(c==28)
						{
							printf("%d %d %d\n",a,b+1,1);
						}
						else
						{
							printf("QWQ\n");
						}
					} 
				}
				else if(b==4||b==6||b==9||b==11)
				{
					if(c<30)
					{
						printf("%d %d %d\n",a,b,c+1);
					}
					else if(c==30)
					{
						printf("%d %d %d\n",a,b+1,1);
					}
					else
					{
						printf("QWQ\n");
					}
				}
				else
				{
					printf("QWQ\n");
				}
			}
		}
	}
}
