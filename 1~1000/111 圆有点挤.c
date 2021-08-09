#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        int A,B,R1,R2;
        scanf("%d%d%d%d",&A,&B,&R1,&R2);
        if(A>B)
		{
			int temp=A;
			A=B;
			B=temp; 
		} 
        if(R1>R2)
		{
			int temp=R1;
			R1=R2;
			R2=temp; 
		}
        int difA=A-R1-R2;
        int difB=B-R1-R2;
        if(2*R1>A||2*R2>A||difA<0||difB<0)
		{
            printf("NO\n");
        }
		else
		{
            difA*=difA;
            difB*=difB;
            int dif=R1+R2;
            dif*=dif;
            if(dif>difA+difB)
			{
                printf("NO\n");
            }
			else
			{
                printf("YES\n");
            }
        }
    }
    return 0;
}
